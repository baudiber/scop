/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_inputs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 14:09:37 by baudiber          #+#    #+#             */
/*   Updated: 2020/07/22 18:27:56 by baudibert        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/scop.h"

void 	flat_color_selected(void)
{
	t_env *e;

	e = get_env();
	e->shading = 0;
}

void 	smooth_color_selected(void)
{
	t_env *e;

	e = get_env();
	e->shading = 1;
	if (e->transition < 1.0f)
		e->transition += 0.05;
}

void 	texture_selected(void)
{
	t_env *e;

	e = get_env();
	if (e->mesh.textured)
		e->shading = 2;
	else
		printf("no texture coordinates found!\n");
}

void 	go_up(void)
{
	t_env *e;

	e = get_env();
	e->camera.y += 0.01f;
}

void 	go_down(void)
{
	t_env *e;

	e = get_env();
	e->camera.y -= 0.01f;
}

void 	go_right(void)
{
	t_env *e;

	e = get_env();
	e->camera.x += 0.01f;
}

void 	go_left(void)
{
	t_env *e;

	e = get_env();
	e->camera.x -= 0.01f;
}

void 	go_far(void)
{
	t_env *e;

	e = get_env();
	e->camera.z -= 0.01f;
}

void 	go_close(void)
{
	t_env *e;

	e = get_env();
	e->camera.z += 0.01f;
}

void process_inputs(GLFWwindow *window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
	if (glfwGetKey(window, GLFW_KEY_COMMA) == GLFW_PRESS) 
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	if (glfwGetKey(window, GLFW_KEY_PERIOD) == GLFW_PRESS) 
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	if (glfwGetKey(window, GLFW_KEY_SLASH) == GLFW_PRESS) 
		glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
	if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS) 
		texture_selected();
	if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS) 
		flat_color_selected();
	if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS) 
		smooth_color_selected();
	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) 
		go_up();
	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) 
		go_down();
	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) 
		go_right();
	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) 
		go_left();
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) 
		go_far();
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) 
		go_close();
}
