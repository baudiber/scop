/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_inputs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 14:09:37 by baudiber          #+#    #+#             */
/*   Updated: 2020/11/02 00:50:43 by baudibert        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/scop.h"

void 	set_shading(int shading)
{
	t_env *e;

	e = get_env();
	if (shading < 2)
		e->transition = 0.0f;
	if (shading >= 2 && !e->mesh.has_vts)
		return;
	e->shading = shading;
}

void 	movement(int dir)
{
	t_env *e;

	e = get_env();
	if (dir == 0)
		e->camera.y += 0.1f;
	else if (dir == 1)
		e->camera.y -= 0.1f;
	else if (dir == 2)
		e->camera.x += 0.1f;
	else if (dir == 3)
		e->camera.x -= 0.1f;
	else if (dir == 4)
		e->camera.z += 0.1f;
	else if (dir == 5)
		e->camera.z -= 0.1f;
}

void process_movement(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
        movement(0);
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
        movement(1);
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
        movement(2);
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
        movement(3);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        movement(4);
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        movement(5);
}

void process_inputs(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
	if (glfwGetKey(window, GLFW_KEY_COMMA) == GLFW_PRESS) 
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	if (glfwGetKey(window, GLFW_KEY_PERIOD) == GLFW_PRESS) 
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	if (glfwGetKey(window, GLFW_KEY_SLASH) == GLFW_PRESS) 
		glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
	if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS) 
		set_shading(2);
	if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS) 
		set_shading(0);
	if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS) 
		set_shading(1);
	if (glfwGetKey(window, GLFW_KEY_MINUS) == GLFW_PRESS)
		set_shading(3);
	if (glfwGetKey(window, GLFW_KEY_EQUAL) == GLFW_PRESS) 
		set_shading(2);
	process_movement(window);
}
