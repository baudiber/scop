/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 12:31:24 by baudiber          #+#    #+#             */
/*   Updated: 2020/07/07 19:11:53 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"
#include <stdio.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	(void)window;
	glViewport(0, 0, width, height);
}

void error_callback(int error, const char* description)
{
	(void)error;
    ft_putstr("Error: ");
    ft_putendl(description);
}

bool init(t_env *e)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
	glfwSetErrorCallback(error_callback);

	glfwWindowHint(GLFW_SAMPLES, 8);
	e->window = glfwCreateWindow( WIN_W, WIN_H, "scop", NULL, NULL);
	if (!e->window) 
	{
		ft_putendl("Failed to create GLFW window");
		glfwTerminate();
		return (false);
	}
	glfwMakeContextCurrent(e->window);
	glfwSetFramebufferSizeCallback(e->window, framebuffer_size_callback);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		ft_putendl("Failed to init GLAD");
		return (false);
	}
	e->shading = 1;

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_PROGRAM_POINT_SIZE);
	glEnable(GL_MULTISAMPLE);
    return (true);
}
