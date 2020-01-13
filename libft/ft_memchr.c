/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:48:09 by baudiber          #+#    #+#             */
/*   Updated: 2017/11/09 21:52:33 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int					i;
	const unsigned char	*s2;

	s2 = s;
	i = 0;
	while (n--)
	{
		if (s2[i] == (unsigned char)c)
		{
			s2 = &s2[i];
			return ((void*)s2);
		}
		i++;
	}
	return (NULL);
}
