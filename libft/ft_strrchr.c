/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:02:25 by baudiber          #+#    #+#             */
/*   Updated: 2017/11/13 12:07:59 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		count;
	int		len;
	char	*tmp;

	tmp = NULL;
	count = 0;
	len = ft_strlen((char*)s) + 1;
	while (len--)
	{
		if (s[count] == (char)c)
		{
			tmp = (char*)&s[count];
		}
		count++;
	}
	if (tmp)
		return (tmp);
	return (NULL);
}
