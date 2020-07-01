/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 14:09:41 by baudiber          #+#    #+#             */
/*   Updated: 2020/07/01 18:39:23 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

int     main(int ac, char **av)
{
    t_env   e;

    if (ac != 2 || ft_strequ("", av[1]))
    {
        ft_putendl("usage : ./scop file.obj");
		return (0);
    }

    ft_putstr("Opening ");
    ft_putendl(av[1]);
	ft_bzero(&e, sizeof(t_env));
    if (!parse_file(av[1], &e))
    {
        ft_putendl("ERROR parsing file");
		return (0);
    }
    if (!init(&e))
    {
        ft_putendl("ERROR during init");
        return (-1);
    }

    run(&e);

	glfwTerminate();
    return (0);
}
