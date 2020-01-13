/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 22:34:17 by baudiber          #+#    #+#             */
/*   Updated: 2018/05/14 17:16:15 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsort(char **tab)
{
	size_t	a;
	size_t	b;
	char	*tmp;
	size_t	i;

	if (!tab)
		return (NULL);
	i = ft_tablen(tab);
	a = 0;
	while (a < i - 1)
	{
		b = a + 1;
		while (b < i)
		{
			if (ft_strcmp(tab[a], tab[b]) > 0)
			{
				tmp = tab[a];
				tab[a] = tab[b];
				tab[b] = tmp;
			}
			b++;
		}
		a++;
	}
	return (tab);
}
