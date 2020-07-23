/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 16:16:47 by baudiber          #+#    #+#             */
/*   Updated: 2020/07/23 13:07:49 by baudibert        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"

void free_vert_lst(t_env *e)
{
	t_vert_lst *it;

	it = e->vert_lst;
	while (it)
	{
		free(it);
		it = it->next;
	}
}

bool float_cmp(float float1, float float2)
{
	return (fabsf(float1 - float2) < FLT_EPSILON);
}

void 		process_fdata(t_env *e)
{
	t_f_lst 	*f_it;
	int 			i;

	f_it = e->f_lst->next;
	i = 0;
	while (f_it)
	{
		e->data.indices[i].x = f_it->indices[0];
		e->data.indices[i + 1].x = f_it->indices[1];
		e->data.indices[i + 2].x = f_it->indices[2];
		(f_it->nb == 4) ? e->data.indices[i + 3].x = f_it->indices[3] : 0;
		if (e->mesh.textured)
		{
			e->data.indices[i].y = f_it->tex_cords[0];
			e->data.indices[i + 1].y = f_it->tex_cords[1];
			e->data.indices[i + 2].y = f_it->tex_cords[2];
			(f_it->nb == 4) ? e->data.indices[i + 3].y = f_it->tex_cords[3] : 0;
		}
		i += f_it->nb;
		f_it = f_it->next;
	}
}

int 	vert_already_exists(t_vertex vert, t_env *e)
{
	t_vert_lst *vert_it;

	vert_it = e->vert_lst->next;
	while (vert_it)
	{
		if (float_cmp(vert_it->v.pos.x, vert.pos.x) && 
			float_cmp(vert_it->v.pos.y, vert.pos.y) && 
			float_cmp(vert_it->v.pos.z, vert.pos.z) && 
			float_cmp(vert_it->v.text_coords.x, vert.text_coords.x) && 
			float_cmp(vert_it->v.text_coords.y, vert.text_coords.y))
			return (vert_it->v.index);
		vert_it = vert_it->next;
	}
	return (-1);
}

t_vert_lst 	*add_vert_node(t_vertex vert)
{
	t_vert_lst *new;

	new = (t_vert_lst *)malloc(sizeof(t_vert_lst));	
	if (!new)
	{
		printf("malloc error\n");
		exit (-1);
	}
	new->v = vert;
	new->next = NULL;
	return (new);
}

//TODO CHECK FOR SIZES BEFORE ACCESSING INDEX
void 	create_vert_lst(t_env *e)
{
	e->vert_lst = (t_vert_lst *)malloc(sizeof(t_vert_lst));	
	if (!e->vert_lst)
	{
		printf("malloc error\n");
		exit (-1);
	}

	t_vert_lst *vert_it;
	vert_it = e->vert_lst;

	t_vertex tmp_vert;
	int vert_nb;
	int found_index;
	vert_nb = 0;
	for (unsigned int i = 0; i < e->data_size.indice_nb; i++)
	{
		tmp_vert.pos = e->data.v[e->data.indices[i].x - 1];
		if (e->mesh.textured)
			tmp_vert.text_coords = e->data.vt[e->data.indices[i].y - 1];
		else
			tmp_vert.text_coords = vec2(0.0f, 0.0f);
		if (vert_nb == 0 || (found_index = vert_already_exists(tmp_vert, e)) < 0)
		{
			vert_it->next = add_vert_node(tmp_vert);
			vert_it = vert_it->next;
			vert_it->v.index = vert_nb;
			vert_nb++;
		}
	}
	e->data_size.vert_nb = vert_nb;
	printf("final vert nb: %d\n", vert_nb);
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
		if (e->mesh.textured)
			tmp_vert.text_coords = e->data.vt[e->data.indices[i].y - 1];
		found_index = vert_already_exists(tmp_vert, e);
		e->mesh.index_buffer[i] = found_index;
		i++;
	}
}

void 	create_vert_data(t_env *e)
{
	t_vert_lst *it;
	int 		i;

	it = e->vert_lst->next;
	i = 0;
	while (it)
	{
		e->mesh.verts[i++] = it->v;
		it = it->next;
	}
}

void 		process_vtdata(t_env *e)
{
	t_vt_lst 		*vt_it;
	int 			i;

	vt_it = e->vt_lst->next;
	i = 0;
	while (vt_it)
	{
		e->data.vt[i] = vt_it->uv;
		vt_it = vt_it->next;
		i++;
	}
}

void 		process_vdata(t_env *e)
{
	t_v_lst 		*v_it;
	int 			i;

	v_it = e->v_lst->next;
	i = 0;
	while (v_it)
	{
		e->data.v[i] = v_it->pos;
		v_it = v_it->next;
		i++;
	}
}

void 	malloc_vertices(t_env *e)
{
	if (!(e->mesh.verts = (t_vertex *)malloc(sizeof(t_vertex) * e->data_size.vert_nb)))
	{
		printf("verts malloc error");
		exit(-1);
	}
	if (!(e->mesh.index_buffer = (unsigned int *)malloc(sizeof(unsigned int) * e->data_size.indice_nb)))
	{
		printf("index_buffer malloc error");
		exit(-1);
	}
}

void 	process_data(t_env *e)
{
	process_vdata(e);
	if (e->mesh.textured)
		process_vtdata(e);
	process_fdata(e);
	create_vert_lst(e);
	malloc_vertices(e);
	create_vert_data(e);
	create_index_buffer(e);
	free_vert_lst(e);
}
