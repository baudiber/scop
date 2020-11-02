/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 16:16:47 by baudiber          #+#    #+#             */
/*   Updated: 2020/10/30 15:32:39 by baudibert        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scop.h>

void 		process_triangle(t_env *e, int i, t_f_lst *f_it)
{
	e->data.indices[i].x = f_it->indices[0];
	e->data.indices[i + 1].x = f_it->indices[1];
	e->data.indices[i + 2].x = f_it->indices[2];
	if (e->mesh.has_vts)
	{
		e->data.indices[i].y = f_it->tex_cords[0];
		e->data.indices[i + 1].y = f_it->tex_cords[1];
		e->data.indices[i + 2].y = f_it->tex_cords[2];
	}
//	if (e->mesh.has_vns)
//	{
//		e->data.indices[i].z = f_it->normals[0];
//		e->data.indices[i + 1].z = f_it->normals[1];
//		e->data.indices[i + 2].z = f_it->normals[2];
//	}
}

void 		process_quad(t_env *e, int i, t_f_lst *f_it)
{
	e->data.indices[i].x = f_it->indices[0];
	e->data.indices[i + 1].x = f_it->indices[1];
	e->data.indices[i + 2].x = f_it->indices[2];
	e->data.indices[i + 3].x = f_it->indices[2];
	e->data.indices[i + 4].x = f_it->indices[3];
	e->data.indices[i + 5].x = f_it->indices[0];
	if (e->mesh.has_vts)
	{
		e->data.indices[i].y = f_it->tex_cords[0];
		e->data.indices[i + 1].y = f_it->tex_cords[1];
		e->data.indices[i + 2].y = f_it->tex_cords[2];
		e->data.indices[i + 3].y = f_it->tex_cords[2];
		e->data.indices[i + 4].y = f_it->tex_cords[3];
		e->data.indices[i + 5].y = f_it->tex_cords[0];
	}
//	if (e->mesh.has_vns)
//	{
//		e->data.indices[i].z = f_it->normals[0];
//		e->data.indices[i + 1].z = f_it->normals[1];
//		e->data.indices[i + 2].z = f_it->normals[2];
//		e->data.indices[i + 3].z = f_it->normals[2];
//		e->data.indices[i + 4].z = f_it->normals[3];
//		e->data.indices[i + 5].z = f_it->normals[0];
//	}
}

void 		process_fdata(t_env *e)
{
	t_f_lst 	*f_it;
	int 			i;

	f_it = e->f_lst->next;
	i = 0;
	while (f_it)
	{
		if (f_it->quad == false)
		{
			process_triangle(e, i ,f_it);
			i += 3;
		}
		else
		{
			process_quad(e, i ,f_it);
			i += 6;
		}
		f_it = f_it->next;
	}
}
