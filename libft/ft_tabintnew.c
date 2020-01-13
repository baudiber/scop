/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabintnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 21:26:44 by baudiber          #+#    #+#             */
/*   Updated: 2017/11/28 21:26:45 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_tabintnew(size_t size)
{
	int		*tab;

	tab = (int *)malloc(sizeof(int) * size);
	if (!tab)
		return (NULL);
	return (tab);
}
