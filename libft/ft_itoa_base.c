/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 15:39:01 by baudiber          #+#    #+#             */
/*   Updated: 2018/06/28 23:14:17 by baudiber         ###   ########.fr       */
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

char			*ft_itoa_base(int value, int base)
{
	char	*str;
	int		i;
	int		neg;

	neg = 0;
	i = 1;
	if (value < 0)
	{
		if (base == 10)
			neg = 1;
		value = value * -1;
	}
	while (rec(base, i) - 1 < value)
		i++;
	if (!(str = (char *)malloc(sizeof(char) * i)))
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
