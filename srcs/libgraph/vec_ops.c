/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 15:16:10 by baudiber          #+#    #+#             */
/*   Updated: 2020/11/02 19:35:40 by baudibert        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scop.h>

t_vec3		vec3(float x, float y, float z)
{
	t_vec3 ret;

	ret.x = x;
	ret.y = y;
	ret.z = z;
	return (ret);
}

t_vec2		vec2(float x, float y)
{
	t_vec2 ret;

	ret.x = x;
	ret.y = y;
	return (ret);
}

float		magnitude_vec3(t_vec3 v)
{
	return (sqrtf(v.x * v.x + v.y * v.y + v.z * v.z));
}

t_vec3		normalize_vec3(t_vec3 v)
{
	t_vec3		res;
	float		mag;

	mag = magnitude_vec3(v);
	if (mag == 0)
	{
		ft_putendl("vec3 magnitude is 0");
		return (v);
	}
	res.x = v.x / mag;
	res.y = v.y / mag;
	res.z = v.z / mag;
	return (res);
}
