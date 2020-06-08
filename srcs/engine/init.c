/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 12:31:24 by baudiber          #+#    #+#             */
/*   Updated: 2020/06/08 14:10:16 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	(void)window;
	glViewport(0, 0, width, height);
}

bool init(void)
{
    t_env *e;

    e = get_env();

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	e->window = glfwCreateWindow( WIN_W, WIN_H, "scop", NULL, NULL);
	if (!e->window) 
	{
		ft_putendl("Failed to create GLFW window");
		glfwTerminate();
		return (false);
	}
	glfwMakeContextCurrent(e->window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		ft_putendl("Failed to init GLAD");
		return (false);
	}
	glViewport(0, 0, WIN_W, WIN_H);
	glfwSetFramebufferSizeCallback(e->window, framebuffer_size_callback);


    return (true);
}
