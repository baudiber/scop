/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 15:16:10 by baudiber          #+#    #+#             */
/*   Updated: 2020/06/22 19:26:26 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"

t_mat4x4	identity_mat4x4(void)
{
	t_mat4x4	mat;

	ft_bzero(&mat, sizeof(t_mat4x4));
	mat.m[0][0] = 1.0;
	mat.m[1][1] = 1.0;
	mat.m[2][2] = 1.0;
	mat.m[3][3] = 1.0;
	return (mat);
}

t_mat4x4	scale_mat4x4(t_vec4 scale)
{
	t_mat4x4	mat;

	mat = identity_mat4x4();
	mat.m[0][0] = scale.x;
	mat.m[1][1] = scale.y;
	mat.m[2][2] = scale.z;
	mat.m[3][3] = 1.0;
	return (mat);
}

t_mat4x4	translate_mat4x4(t_mat4x4 mat, t_vec4 vec)
{
	mat.m[3][0] = vec.x;
	mat.m[3][1] = vec.y;
	mat.m[3][2] = vec.z;
	mat.m[3][3] = vec.w; 
	return (mat);
}
