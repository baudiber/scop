/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudibert <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:24:44 by baudibert         #+#    #+#             */
/*   Updated: 2020/11/02 19:26:02 by baudibert        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scop.h>

void	clean_exit(const char *msg)
{
	printf("%s\n", msg);
	glfwTerminate();
	exit(1);
}

t_env	*get_env(void)
{
	static t_env	e;

	return (&e);
}

void	print_man(void)
{
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~~~~~~~~~~~ SCOP ~~~~~~~~~~~~~\n");
	printf("Commands: \n");
	printf("WS to zoom\n");
	printf("ARROWS for movement\n");
	printf("C F T to switch shading modes\n");
	printf("ESC to quit\n");
	printf(". for WIREFRAME view\n");
	printf("/ for VERTEX view\n");
	printf(", revert to FILLED view\n");
	printf("- switch to Minecraft texture\n");
	printf("+ switch to unicorn kitty texture (sigh)\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("Some shading and texturing options will not work unless\n");
	printf("the obj has texture or normal coordinates.\n");
	printf("\n");
}

void	scop(char *av1)
{
	t_env	*e;

	e = get_env();
	ft_bzero(e, sizeof(t_env));
	print_man();
	ft_putstr("Opening ");
	ft_putendl(av1);
	parse_obj(av1, e);
	parse_shaders(e);
	init(e);
	run(e);
	glfwTerminate();
}
