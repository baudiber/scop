/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vert_creation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudibert <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:57:24 by baudibert         #+#    #+#             */
/*   Updated: 2020/11/02 20:03:06 by baudibert        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scop.h>

int			vert_already_exists(t_vertex vert, t_env *e)
{
	t_vert_lst		*vert_it;

	vert_it = e->vert_lst->next;
	while (vert_it)
	{
		if (float_cmp(vert_it->v.pos.x, vert.pos.x) &&
				float_cmp(vert_it->v.pos.y, vert.pos.y) &&
				float_cmp(vert_it->v.pos.z, vert.pos.z) &&
				float_cmp(vert_it->v.normal.x, vert.normal.x) &&
				float_cmp(vert_it->v.normal.y, vert.normal.y) &&
				float_cmp(vert_it->v.normal.z, vert.normal.z) &&
				float_cmp(vert_it->v.text_coords.x, vert.text_coords.x) &&
				float_cmp(vert_it->v.text_coords.y, vert.text_coords.y))
			return (vert_it->v.index);
		vert_it = vert_it->next;
	}
	return (-1);
}

void		create_vert_data(t_env *e)
{
	t_vert_lst	*it;
	int			i;

	it = e->vert_lst->next;
	i = 0;
	while (it)
	{
		e->mesh.verts[i++] = it->v;
		it = it->next;
	}
}

t_vert_lst	*add_vert_node(t_vertex vert)
{
	t_vert_lst *new;

	if (!(new = (t_vert_lst *)malloc(sizeof(t_vert_lst))))
		clean_exit("malloc error");
	new->v = vert;
	new->next = NULL;
	return (new);
}

void		check_indices(int i, t_env *e)
{
	if (e->data.indices[i].x > (int)e->data_size.v_nb
			|| e->data.indices[i].x < 0)
		clean_exit("v index problem");
	if (e->mesh.has_vts && (e->data.indices[i].y > (int)e->data_size.vt_nb
				|| e->data.indices[i].y < 0))
		clean_exit("vt index problem");
	if (e->mesh.has_vns && (e->data.indices[i].z > (int)e->data_size.vn_nb
				|| e->data.indices[i].z < 0))
		clean_exit("vt index problem");
}

void		create_vert_lst(t_env *e)
{
	int				vert_nb;
	int				i;
	t_vert_lst		*vert_it;
	t_vertex		tmp_vert;

	vert_nb = 0;
	vert_it = e->vert_lst;
	i = -1;
	while (++i < (int)e->data_size.indice_nb)
	{
		check_indices(i, e);
		tmp_vert.pos = e->data.v[e->data.indices[i].x - 1];
		tmp_vert.text_coords = (e->mesh.has_vts) ?
			e->data.vt[e->data.indices[i].y - 1] : vec2(0.0f, 0.0f);
		tmp_vert.normal = (e->mesh.has_vns) ?
			e->data.vn[e->data.indices[i].z - 1] : vec3(0.0f, 0.0f, 0.0f);
		if (vert_nb == 0 || vert_already_exists(tmp_vert, e) < 0)
		{
			vert_it->next = add_vert_node(tmp_vert);
			vert_it = vert_it->next;
			vert_it->v.index = vert_nb;
			vert_nb++;
		}
	}
	e->data_size.vert_nb = vert_nb;
}
