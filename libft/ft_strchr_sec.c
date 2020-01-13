/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_sec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 23:10:38 by baudiber          #+#    #+#             */
/*   Updated: 2018/06/28 23:11:35 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr_sec(const char *s, int c)
{
	int		count;
	int		len;

	count = 0;
	if (!s)
		return (NULL);
	len = ft_strlen((char*)s) + 1;
	while (len--)
	{
		if (s[count] == (char)c)
			return ((char*)&s[count]);
		count++;
	}
	return (NULL);
}
