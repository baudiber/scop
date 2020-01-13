/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 22:27:31 by baudiber          #+#    #+#             */
/*   Updated: 2017/11/16 02:57:34 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	int		size;
	int		ngtv;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = (int)ft_intlen(n);
	if (!(str = ft_strnew(size)))
		return (NULL);
	ngtv = 0;
	size--;
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
		ngtv = 1;
	}
	while (ngtv - 1 < size)
	{
		str[size] = '0' + (n % 10);
		n /= 10;
		size--;
	}
	return (str);
}
