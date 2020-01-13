/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 14:55:46 by baudiber          #+#    #+#             */
/*   Updated: 2017/11/16 18:26:52 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	str = NULL;
	if (s)
	{
		str = (char*)malloc(sizeof(char) * len + 1);
		if (!str)
			return (NULL);
		i = 0;
		while (len--)
			str[i++] = s[start++];
		str[i] = '\0';
	}
	return (str);
}
