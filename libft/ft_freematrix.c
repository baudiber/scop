/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freematrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 18:48:59 by baudiber          #+#    #+#             */
/*   Updated: 2018/05/14 17:18:03 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freematrix(char ***tab)
{
	size_t	i;
	size_t	size;

	if (!tab)
		return ;
	size = ft_matrixlen(tab);
	i = 0;
	while (i < size + 1)
	{
		ft_freetab(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}
