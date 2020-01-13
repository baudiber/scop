/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 23:42:08 by baudiber          #+#    #+#             */
/*   Updated: 2017/11/16 02:59:21 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;

	if (!(*needle))
		return ((char*)haystack);
	i = ft_strlen(needle);
	j = 0;
	while (j < (int)ft_strlen(haystack))
	{
		if (ft_strncmp((char*)&haystack[j], (char*)needle, i) == 0)
			return ((char*)&haystack[j]);
		j++;
	}
	return (NULL);
}
