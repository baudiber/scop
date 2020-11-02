/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 16:39:12 by baudiber          #+#    #+#             */
/*   Updated: 2020/11/02 17:44:24 by baudibert        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scop.h>

t_mat4x4 	rotation_mat4x4(t_mat4x4 src_mat, float angle, t_vec3 axis)
{
    t_mat4x4 rot_mat;
    t_vec3   norm_axis;
    t_vec3   temp;

    rot_mat = src_mat;
    norm_axis = normalize_vec3(axis);
    temp.x = norm_axis.x * (1.0 - cos(angle));
    temp.y = norm_axis.y * (1.0 - cos(angle));
    temp.z = norm_axis.z * (1.0 - cos(angle));
    rot_mat.m[0][0] = cos(angle) + temp.x * norm_axis.x;
    rot_mat.m[0][1] = 0 + temp.x * norm_axis.y + sin(angle) * norm_axis.z;
    rot_mat.m[0][2] = 0 + temp.x * norm_axis.z - sin(angle) * norm_axis.y;
    rot_mat.m[1][0] = 0 + temp.y * norm_axis.x - sin(angle) * norm_axis.z;
    rot_mat.m[1][1] = cos(angle) + temp.y * norm_axis.y;
    rot_mat.m[1][2] = 0 + temp.y * norm_axis.z + sin(angle) * norm_axis.x;
    rot_mat.m[2][0] = 0 + temp.z * norm_axis.x + sin(angle) * norm_axis.y;
    rot_mat.m[2][1] = 0 + temp.z * norm_axis.y - sin(angle) * norm_axis.x;
    rot_mat.m[2][2] = cos(angle) + temp.z * norm_axis.z;
    rot_mat.m[3][3] = 1.0f;
    return (mult_4x4mat(src_mat, rot_mat));
}

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

t_mat4x4	translate_mat4x4(t_mat4x4 mat, t_vec3 vec)
{
    mat.m[3][0] = (vec.x * mat.m[0][0] + vec.x * mat.m[0][1] + vec.x * mat.m[0][2]) + mat.m[3][0];
    mat.m[3][1] = (vec.y * mat.m[1][0] + vec.y * mat.m[1][1] + vec.y * mat.m[1][2]) + mat.m[3][1];
    mat.m[3][2] = (vec.z * mat.m[2][0] + vec.z * mat.m[2][1] + vec.z * mat.m[2][2]) + mat.m[3][2];
    return (mat);
}

t_mat4x4 	perspective(float fovy, float aspect_ratio, float near, float far)
{
    t_mat4x4 	mat;
    float  		tan_half_fovy;

    ft_bzero(&mat, sizeof(t_mat4x4));
    tan_half_fovy = tan(fovy / 2);
    mat.m[0][0] = 1.0f / (aspect_ratio * tan_half_fovy);
    mat.m[1][1] = 1.0f / tan_half_fovy;
    mat.m[2][2] = -(far + near) / (far - near);
    mat.m[2][3] = -1.0f;
    mat.m[3][2] = -(2.0f * far * near) / (far - near);
    return (mat);
}
