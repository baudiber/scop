/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 15:16:10 by baudiber          #+#    #+#             */
/*   Updated: 2020/06/25 18:58:09 by baudiber         ###   ########.fr       */
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

float 		magnitude_vec3(t_vec3 v)
{
	return (sqrtf(v.x * v.x + v.y * v.y + v.z * v.z));
}

t_vec3 		normalize_vec3(t_vec3 v)
{
	t_vec3  res;
	float 	mag;

	mag = magnitude_vec3(v);
	if (mag < 0)
	{
		ft_putendl("vec3 magnitude is below 0");
		return (v);
	}
	res.x = v.x / mag;
	res.y = v.y / mag;
	res.z = v.z / mag;
	return res;
}

void 		print_mat(t_mat4x4 mat)
{
	printf("%f %f %f %f\n", mat.m[0][0], mat.m[0][1], mat.m[0][2], mat.m[0][3]);
	printf("%f %f %f %f\n", mat.m[1][0], mat.m[1][1], mat.m[1][2], mat.m[1][3]);
	printf("%f %f %f %f\n", mat.m[2][0], mat.m[2][1], mat.m[2][2], mat.m[2][3]);
	printf("%f %f %f %f\n", mat.m[3][0], mat.m[3][1], mat.m[3][2], mat.m[3][3]);
}

t_mat4x4 	rotation_mat4x4(t_mat4x4 src_mat, float angle, t_vec3 axis)
{
	t_mat4x4 rot_mat;
	float    cos_angle;
	float    sin_angle;
	t_vec3   norm_axis;
	t_vec3   temp;

	cos_angle = cos(angle);
	sin_angle = sin(angle);
	norm_axis = normalize_vec3(axis);	
	temp.x = norm_axis.x * (1 - cos_angle);
	temp.y = norm_axis.y * (1 - cos_angle);
	temp.z = norm_axis.z * (1 - cos_angle);

	rot_mat.m[0][0] = cos_angle + temp.x * norm_axis.x;
	rot_mat.m[0][1] = 0 + temp.x * norm_axis.y + sin_angle * norm_axis.z;
	rot_mat.m[0][2] = 0 + temp.x * norm_axis.z - sin_angle * norm_axis.y;
	
	rot_mat.m[1][0] = 0 + temp.y * norm_axis.x - sin_angle * norm_axis.z;
	rot_mat.m[1][1] = cos_angle + temp.y * norm_axis.y;
	rot_mat.m[1][2] = 0 + temp.y * norm_axis.z + sin_angle * norm_axis.x;

	rot_mat.m[2][0] = 0 + temp.z * norm_axis.x + sin_angle * norm_axis.y;
	rot_mat.m[2][1] = 0 + temp.z * norm_axis.y - sin_angle * norm_axis.x;
	rot_mat.m[2][2] = cos_angle + temp.z * norm_axis.z;

	rot_mat.m[3][0] = 0.0f;
	rot_mat.m[3][1] = 0.0f;
	rot_mat.m[3][2] = 0.0f;
	rot_mat.m[3][3] = 1.0f;
	return (mult_4x4mat(rot_mat, src_mat));
}

float 		deg_to_rad(float angle)
{
	return (angle * (M_PI / 180));
}

float 		rad_to_deg(float angle)
{
	return (angle * (180 / M_PI));
}
