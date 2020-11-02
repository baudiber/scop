/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 16:19:50 by baudiber          #+#    #+#             */
/*   Updated: 2020/11/02 16:16:06 by baudibert        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scop.h>

void 	create_index_buffer(t_env *e)
{
    t_vertex 		tmp_vert;
    int 			found_index;
    unsigned int 	i;

    i = 0;
    while (i < e->data_size.indice_nb)
    {
        tmp_vert.pos = e->data.v[e->data.indices[i].x - 1];
        if (e->mesh.has_vts)
            tmp_vert.text_coords = e->data.vt[e->data.indices[i].y - 1];
        if (e->mesh.has_vns)
            tmp_vert.normal = e->data.vn[e->data.indices[i].z - 1];
        found_index = vert_already_exists(tmp_vert, e);
        e->mesh.index_buffer[i] = found_index;
        i++;
    }
}

void 	process_data(t_env *e)
{
    process_vdata(e);
    if (e->mesh.has_vts)
        process_vtdata(e);
	if (e->mesh.has_vns)
        process_vndata(e);
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
		clean_exit("error parsing file");
	process_data(e);
	get_min_max(e);
	normalize_mesh(e);
	get_min_max(e);
	create_vertices(e);
	free_lists(e);
	free_raw_data(e);
	printf("has vts: %d, has vns: %d, vnb: %d, vtnb: %d, vnnb: %d, indexnb: %d,"
        " final_vert_nb: %d\n",
        e->mesh.has_vts, e->mesh.has_vns, e->data_size.v_nb,
        e->data_size.vt_nb, e->data_size.vn_nb, e->data_size.indice_nb,
		e->data_size.vert_nb);
}
