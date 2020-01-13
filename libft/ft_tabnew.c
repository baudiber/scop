/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 21:26:55 by baudiber          #+#    #+#             */
/*   Updated: 2018/06/25 21:16:01 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabnew(size_t size)
{
	char	**tab;

	tab = (char **)malloc(sizeof(char *) * size + 1);
	if (!tab)
		return (NULL);
	tab[size] = NULL;
	return (tab);
}
