/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 16:19:50 by baudiber          #+#    #+#             */
/*   Updated: 2020/11/02 15:16:48 by baudibert        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scop.h>

//float 	find_furthest_point(t_env *e)
//{
//	return (fmax(fabs(e->data_size.max.z), fmax(fabs(e->data_size.min.z),
//		fmax(fabs(e->data_size.max.y), fmax(fabs(e->data_size.min.y),
//		fmax(fabs(e->data_size.max.x), fabs(e->data_size.min.x)))))));
//}
//
//void 	normalize_data(t_env *e)
//{
//	unsigned int i;
//	float 			div;
//
//	div = find_furthest_point(e);
//	i = 0;
//	while (i < e->data_size.v_nb)
//	{
//		e->data.v[i].x /= div;
//		e->data.v[i].y /= div;
//		e->data.v[i].z /= div;
//		i++;
//	}
//}
//
void 	test(t_env *e)
{
	unsigned int 	i;
	float 			scale;

	scale = fmin(2.0f / (e->data_size.max.x - e->data_size.min.x),
            fmin(2.0f / (e->data_size.max.y - e->data_size.min.y),
            2.0f / (e->data_size.max.z - e->data_size.max.z)));
	i = 0;
	while (i < e->data_size.v_nb)
	{
		e->data.v[i].x = (e->data.v[i].x - 0.5 * (e->data_size.min.x 
			+ e->data_size.max.x)) * scale;
		e->data.v[i].y = (e->data.v[i].y - 0.5 * (e->data_size.min.y
			+ e->data_size.max.y)) * scale;
		e->data.v[i].z = (e->data.v[i].z - 0.5 * (e->data_size.min.z
			+ e->data_size.max.z)) * scale;
		i++;
	}
}

//void 	translate_model(t_env *e)
//{
//	unsigned int i;
//
//	i = 0;
//	while (i < e->data_size.v_nb)
//	{
//		e->data.v[i].x += -(e->data_size.max.x + e->data_size.min.x) / 2.0;
//		e->data.v[i].y += -(e->data_size.max.y + e->data_size.min.y) / 2.0;
//		e->data.v[i].z += -(e->data_size.max.z + e->data_size.min.z) / 2.0;
//		i++;
//	}
//}
//
void 	get_min_max(t_env *e)
{
	unsigned int 	i;

	i = 0;
	e->data_size.min.x = e->data.v[i].x;
	e->data_size.max.x = e->data.v[i].x;
	e->data_size.min.y = e->data.v[i].y;
	e->data_size.max.y = e->data.v[i].y;
	e->data_size.min.z = e->data.v[i].z;
	e->data_size.max.z = e->data.v[i].z;
	while (i < e->data_size.v_nb)
	{
		if (e->data.v[i].x < e->data_size.min.x)
			e->data_size.min.x = e->data.v[i].x;
		else if (e->data.v[i].x > e->data_size.max.x)
			e->data_size.max.x = e->data.v[i].x;
		if (e->data.v[i].y < e->data_size.min.y)
			e->data_size.min.y = e->data.v[i].y;
		else if (e->data.v[i].y > e->data_size.max.y)
			e->data_size.max.y = e->data.v[i].y;
		if (e->data.v[i].z < e->data_size.min.z)
			e->data_size.min.z = e->data.v[i].z;
		else if (e->data.v[i].z > e->data_size.max.z)
			e->data_size.max.z = e->data.v[i].z;
		i++;
	}
	printf("minx %f maxx %f\n", e->data_size.min.x, e->data_size.max.x);
	printf("miny %f maxy %f\n", e->data_size.min.y, e->data_size.max.y);
	printf("minz %f maxz %f\n", e->data_size.min.z, e->data_size.max.z);
}

void 	create_index_buffer(t_env *e)
{
    t_vertex tmp_vert;
    int found_index;
    unsigned int i;

    i = 0;
    while (i < e->data_size.indice_nb)
    {
        tmp_vert.pos = e->data.v[e->data.indices[i].x - 1];
        if (e->mesh.has_vts)
            tmp_vert.text_coords = e->data.vt[e->data.indices[i].y - 1];
        found_index = vert_already_exists(tmp_vert, e);
        e->mesh.index_buffer[i] = found_index;
        i++;
    }
}

void 	process_data(t_env *e)
{
    process_vdata(e);
    if (e->mesh.textured)
        process_vtdata(e);
    process_fdata(e);
}

void    create_vertices(t_env *e)
{
    malloc_vert_list(e);
    create_vert_lst(e);
    malloc_vertices(e);
    create_vert_data(e);
    create_index_buffer(e);
    free_vert_lst(e);
}

void 	parse_obj(char *file_path, t_env *e)
{
	if (!read_file(file_path, e))
    {
        ft_putendl("ERROR parsing file");
		exit (-1);
    }
	process_data(e);
	get_min_max(e);
	test(e);
	//normalize_data(e);
	get_min_max(e);
	//translate_model(e);
	create_vertices(e);
	free_lists(e);
	free_raw_data(e);
	printf("textured: %d, normals: ?, vnb: %d, vtnb: %d, vnnb: ?, indexnb: %d,"
        " final_vert_nb: %d\n",
        e->mesh.textured, e->data_size.v_nb,
        e->data_size.vt_nb,  e->data_size.indice_nb, e->data_size.vert_nb);
}
