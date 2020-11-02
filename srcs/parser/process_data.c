/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 16:16:47 by baudiber          #+#    #+#             */
/*   Updated: 2020/11/02 19:49:59 by baudibert        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scop.h>

void		process_vtdata(t_env *e)
{
	t_vt_lst		*vt_it;
	int				i;

	vt_it = e->vt_lst->next;
	i = 0;
	while (vt_it)
	{
		e->data.vt[i] = vt_it->uv;
		vt_it = vt_it->next;
		i++;
	}
}

void		process_vndata(t_env *e)
{
	t_vn_lst		*vn_it;
	int				i;

	vn_it = e->vn_lst->next;
	i = 0;
	while (vn_it)
	{
		e->data.vn[i] = vn_it->normals;
		vn_it = vn_it->next;
		i++;
	}
}

void		process_vdata(t_env *e)
{
	t_v_lst		*v_it;
	int			i;

	v_it = e->v_lst->next;
	i = 0;
	while (v_it)
	{
		e->data.v[i] = v_it->pos;
		v_it = v_it->next;
		i++;
	}
}
