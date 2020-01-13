/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:03:15 by baudiber          #+#    #+#             */
/*   Updated: 2017/11/28 17:22:04 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int					i;
	const unsigned char	*ptr;
	unsigned char		*ptr2;

	ptr = src;
	ptr2 = dst;
	i = 0;
	while (n--)
	{
		ptr2[i] = ptr[i];
		i++;
	}
	return (ptr2);
}
