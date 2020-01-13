/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:25:10 by baudiber          #+#    #+#             */
/*   Updated: 2017/11/29 12:53:26 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_intsort(int *tab, size_t size)
{
	size_t	a;
	size_t	b;
	int		tmp;

	if (!tab)
		return (NULL);
	a = 0;
	while (a < size - 1)
	{
		b = 1 + a;
		while (b < size)
		{
			if (tab[a] > tab[b])
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
