/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_mac.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 14:09:41 by baudiber          #+#    #+#             */
/*   Updated: 2020/11/02 19:24:26 by baudibert        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scop.h>
#include <scop_mac.h>

int		main(int ac, char **av)
{
	if (ac != 2 || ft_strequ("", av[1]))
	{
		ft_putendl("usage : ./scop file.obj");
		ft_putendl("check 3D_objs folder for some examples");
		return (0);
	}
	scop(av[1]);
	return (0);
}
