/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 17:49:08 by baudiber          #+#    #+#             */
/*   Updated: 2018/06/28 23:08:56 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static int		rec(int nb, int pow)
{
	if (pow == 0)
		return (1);
	else
		return (nb * rec(nb, pow - 1));
}

char			*ft_utoa_base(unsigned int value, int base)
{
	char	*str;
	int		i;
	int		neg;

	neg = 0;
	i = 1;
	while (rec(base, i) - 1 < (int)value)
		i++;
	str = (char *)malloc(sizeof(char) * i);
	if (!str)
		return (NULL);
	str[i + neg] = '\0';
	while (i-- > 0)
	{
		str[i + neg] = (value % base) + (value % base > 9 ? 'A' - 10 : '0');
		value /= base;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
