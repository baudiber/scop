/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 02:47:52 by baudiber          #+#    #+#             */
/*   Updated: 2017/11/16 18:31:37 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	rec_fd(int n, int fd)
{
	if (n <= -10)
		rec_fd(n / 10, fd);
	ft_putchar_fd(-(n % 10) + 48, fd);
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		rec_fd(n, fd);
	}
	else
		rec_fd(-n, fd);
}
