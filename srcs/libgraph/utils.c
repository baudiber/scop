/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudibert <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:33:03 by baudibert         #+#    #+#             */
/*   Updated: 2020/11/02 19:33:55 by baudibert        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgraph.h>

bool	float_cmp(float float1, float float2)
{
	return (fabsf(float1 - float2) < FLT_EPSILON);
}

float	deg_to_rad(float angle)
{
	return (angle * (M_PI / 180));
}
