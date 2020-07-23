/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 16:19:50 by baudiber          #+#    #+#             */
/*   Updated: 2020/07/23 11:28:05 by baudibert        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"

void 	get_min_max(t_env *e)
{
	unsigned int i;

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
}

void 		free_lists(t_env *e)
{
	t_f_lst 	*f_it;
	t_v_lst 	*v_it;
	t_vt_lst 	*vt_it;

	v_it = e->v_lst;
	f_it = e->f_lst;
	vt_it = e->vt_lst;
	while (f_it)
	{
		free(f_it);
		f_it = f_it->next;
	}
	while (v_it)
	{
		free(v_it);
		v_it = v_it->next;
	}
	while (vt_it)
	{
		free(vt_it);
		vt_it = vt_it->next;
	}
}

void 	parse_obj(char *file_path, t_env *e)
{
	if (!read_file(file_path, e))
    {
        ft_putendl("ERROR parsing file");
		exit (-1);
    }
	process_data(e);
	free_lists(e);
	get_min_max(e);
}
