/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_linux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 14:09:41 by baudiber          #+#    #+#             */
/*   Updated: 2020/10/23 22:35:43 by wm               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scop.h>

int     main(int ac, char **av)
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
