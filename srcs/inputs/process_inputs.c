/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_inputs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 14:09:37 by baudiber          #+#    #+#             */
/*   Updated: 2020/07/07 19:11:48 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/scop.h"

void process_inputs(GLFWwindow *window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
	if (glfwGetKey(window, GLFW_KEY_COMMA) == GLFW_PRESS) 
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	if (glfwGetKey(window, GLFW_KEY_PERIOD) == GLFW_PRESS) 
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	if (glfwGetKey(window, GLFW_KEY_SLASH) == GLFW_PRESS) 
		glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
	//if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS) 
	//	e->shading = 0;
}
