/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:40:22 by baudiber          #+#    #+#             */
/*   Updated: 2017/11/15 18:38:59 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	len;
	size_t	start;
	char	*str;

	str = NULL;
	if (s)
	{
		len = ft_strlen(s);
		start = 0;
		while ((s[start] == ' ' || s[start] == '\t' || s[start] == '\n') &&
				start < len)
			start++;
		if (start == len)
			return (ft_strnew(0));
		len--;
		while ((s[len] == ' ' || s[len] == '\t' || s[len] == '\n') && s[len])
			len--;
		if (!(str = ft_strnew(len - start)))
			return (NULL);
		str = ft_strsub(s, start, len - start + 1);
	}
	return (str);
}
