/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 16:44:01 by baudiber          #+#    #+#             */
/*   Updated: 2020/06/19 13:47:39 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double 	ft_atod(const char *str)
{
	long	integer_part;
	long	fractional_part;
	long	frac_len;
	double	div;
	char	**split;

	split = ft_strsplit(str, '.');
	if (ft_tablen(split) < 2)
		return (ft_atol(str));
	integer_part = ft_atol(split[0]);
	fractional_part = ft_atol(split[1]);
	if (fractional_part < 0)
		fractional_part = -fractional_part;
	frac_len = ft_intlen(fractional_part);
	if (frac_len <= 0)
		return (integer_part);
	div = ft_pow(10, frac_len);
	if (ft_strlen(split[0]) > 1 && split[0][0] == '-')
		return (-1 * (integer_part + (fractional_part / div)));
	else 
		return (integer_part + (fractional_part / div));
}
