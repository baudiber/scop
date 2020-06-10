/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_inputs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 14:09:37 by baudiber          #+#    #+#             */
/*   Updated: 2020/06/10 14:45:27 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/scop.h"

void process_inputs(GLFWwindow *window) {
	static int mode = 0;

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
	if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS) {
		mode++;
		if (mode > 2) {
			mode = 0;
		}
		if (mode == 0)
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		else if (mode == 1)
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		else if (mode == 2)
			glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
	}
}
