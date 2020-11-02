/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 12:31:24 by baudiber          #+#    #+#             */
/*   Updated: 2020/11/02 19:21:08 by baudibert        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scop.h>

void	framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
	(void)window;
	glViewport(0, 0, width, height);
}

void	error_callback(int error, const char *description)
{
	(void)error;
	ft_putstr("Error: ");
	ft_putendl(description);
}

void	init(t_env *e)
{
	GLenum err;

	glfwInit();
	init_gl_version();
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwSetErrorCallback(error_callback);
	glfwWindowHint(GLFW_SAMPLES, 8);
	e->window = glfwCreateWindow(WIN_W, WIN_H, "scop", NULL, NULL);
	if (!e->window)
		clean_exit("Failed to create GLFW window");
	glfwMakeContextCurrent(e->window);
	glfwSetFramebufferSizeCallback(e->window, framebuffer_size_callback);
	err = glewInit();
	if (err != GLEW_OK)
		clean_exit((const char *)glewGetErrorString(err));
	e->shading = 1;
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_PROGRAM_POINT_SIZE);
	glEnable(GL_MULTISAMPLE);
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
}
