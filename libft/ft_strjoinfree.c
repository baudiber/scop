/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 00:35:08 by baudiber          #+#    #+#             */
/*   Updated: 2018/06/28 23:10:12 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2, int val)
{
	char	*str;

	str = NULL;
	if (s1 && !s2)
		str = ft_strdup(s1);
	if (!s1 && s2)
		str = ft_strdup(s2);
	if (s1 && s2)
		str = ft_strjoin(s1, s2);
	if (val == 1)
		ft_strdel(&s1);
	if (val == 2)
		ft_strdel(&s2);
	if (val == 3)
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	return (str);
}
