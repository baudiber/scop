/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmatrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 22:14:31 by baudiber          #+#    #+#             */
/*   Updated: 2018/05/14 17:16:12 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putmatrix(char ***matrix)
{
	int		i;

	i = 0;
	while (matrix[i])
	{
		ft_putnbr(i + 1);
		ft_putchar('\n');
		ft_puttab(matrix[i]);
		i++;
	}
}
