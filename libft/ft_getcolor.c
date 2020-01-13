/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 23:14:37 by baudiber          #+#    #+#             */
/*   Updated: 2018/06/28 23:14:46 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	This function finds first number in a string and returns it.
**	Number can have several digits and be negative.
**  If no number is found, 0 is returned.
*/

unsigned int	ft_getcolor(char *str)
{
	char			*tmp;
	unsigned int	i;

	i = 0;
	if ((tmp = ft_strchr(str, ',')))
	{
		tmp++;
		i = ft_get_hexa(tmp);
	}
	return (i);
}
