/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 23:15:25 by baudiber          #+#    #+#             */
/*   Updated: 2018/06/28 23:15:26 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_nb(char c, char **base)
{
	int		i;
	char	*b;

	b = *base;
	i = -1;
	while (b[++i])
		if (b[i] == c)
			return (i);
	return (0);
}

int				ft_atoi_base(char *str, char *base)
{
	int		blen;
	int		neg;
	int		res;

	blen = ft_strlen(base);
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	neg = (*str == '-' ? 1 : 0);
	if (*str == '-' || *str == '+')
		str++;
	if (blen == 16)
		if (*str == '0' && str[1] == 'x')
			str += 2;
	res = 0;
	while (*str && strchr(base, *str))
	{
		res = res * blen + get_nb(*str, &base);
		str++;
	}
	return ((neg) ? -res : res);
}
