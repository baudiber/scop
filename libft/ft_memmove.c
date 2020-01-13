/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 23:01:08 by baudiber          #+#    #+#             */
/*   Updated: 2017/11/15 11:50:41 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*source;

	dest = dst;
	source = (unsigned char*)src;
	i = 0;
	if (src == dst)
		return (dst);
	if (source < dest)
	{
		while (len--)
			dest[len] = source[len];
	}
	else
	{
		while (len > i)
		{
			dest[i] = source[i];
			i++;
		}
	}
	return (dst);
}
