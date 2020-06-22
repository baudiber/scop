/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 16:39:12 by baudiber          #+#    #+#             */
/*   Updated: 2020/06/22 19:29:20 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libgraph.h"

t_mat4x4	mult_4x4mat(t_mat4x4 m1, t_mat4x4 m2)
{
	int			i;
	int			j;
	t_mat4x4	res;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			res.m[i][j] = m1.m[i][0] * m2.m[0][j] + \
					m1.m[i][1] * m2.m[1][j] + \
					m1.m[i][2] * m2.m[2][j] + \
					m1.m[i][3] * m2.m[3][j];
			j++;
		}
		i++;
	}
	return (res);
}

t_vec4 	mult_mat4x4(t_vec4 v, t_mat4x4 mat)
{
	t_vec4	res;

	res.x = mat.m[0][0] * v.x;
	res.y = mat.m[1][1] * v.y;
	res.z = mat.m[2][2] * v.z;
	res.w = 1.0;
	return (res);
}
