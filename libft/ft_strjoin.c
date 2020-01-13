/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:42:06 by baudiber          #+#    #+#             */
/*   Updated: 2017/11/15 18:47:24 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;

	str = NULL;
	if (s1 && s2)
	{
		len = (ft_strlen(s1) + ft_strlen(s2));
		str = ft_strnew(len + 1);
		if (!str)
			return (NULL);
		str = ft_strcat(str, s1);
		str = ft_strcat(str, s2);
		str[len + 1] = '\0';
	}
	return (str);
}
