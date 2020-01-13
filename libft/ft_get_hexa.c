/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 23:15:34 by baudiber          #+#    #+#             */
/*   Updated: 2018/06/28 23:16:07 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_get_hexa(char *str)
{
	unsigned int	hexa;

	hexa = ft_strtoui(str, "0123456789ABCDEF");
	return (hexa);
}
