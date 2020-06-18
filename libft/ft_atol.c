/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 14:12:49 by baudiber          #+#    #+#             */
/*   Updated: 2020/06/18 14:13:28 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long		ft_convert(const char *str)
{
	long		j;
	long		i;
	long		k;

	j = ft_strlen(str);
	i = 0;
	k = 0;
	while (j--)
	{
		if (str[i] < '0' || str[i] > '9')
			return (k);
		k *= 10;
		k = k + str[i] - '0';
		i++;
	}
	return (k);
}

long			ft_atol(const char *str)
{
	while (1)
	{
		if (str[0] == ' ' || (str[0] >= 9 && str[0] <= 13))
			str++;
		else if (str[0] == '-')
			return (-ft_convert(str + 1));
		else if (str[0] == '+')
			return (ft_convert(str + 1));
		else if (str[0] >= '0' && str[0] <= '9')
			return (ft_convert(str));
		else
			return (0);
	}
	return (0);
}
