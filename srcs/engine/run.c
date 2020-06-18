/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 15:05:14 by baudiber          #+#    #+#             */
/*   Updated: 2020/06/18 16:12:36 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"

const char *vertexShaderSource = "#version 410 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos, 1.0);\n"
    "}\0";

const char *fragmentShaderSource = "#version 410 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0, 1.0, 1.0, 1.0);\n"
    "}\n\0";

void run(t_env *e)
{
	unsigned int i = 0;
	//while (i < e->data_size.points)
	//{
	//	printf("%f\t%f\t%f\n", e->mesh.verts[i], e->mesh.verts[i + 1], e->mesh.verts[i +2]);
	//	i += 3;
	//}
	i = 0;
	while (i < e->data_size.indices)
	{
		printf("%d\t%d\t%d\n", e->mesh.indices[i], e->mesh.indices[i + 1], e->mesh.indices[i +2]);
		i += 3;
	}



	unsigned int vertex_shader;
	vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex_shader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertex_shader);

	int success;
	char info_log[512];
	glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertex_shader, 512, NULL, info_log);
		ft_putstr("VERTEX SHADER COMPILE ERROR: ");
		ft_putendl(info_log);
	}

	unsigned int fragment_shader;
	fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment_shader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragment_shader);

	glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(fragment_shader, 512, NULL, info_log);
		ft_putstr("FRAGMENT SHADER COMPILE ERROR: ");
		ft_putendl(info_log);
	}

	unsigned int shader_program;
	shader_program = glCreateProgram();
	glAttachShader(shader_program, vertex_shader);
	glAttachShader(shader_program, fragment_shader);
	glLinkProgram(shader_program);

	glGetProgramiv(shader_program, GL_LINK_STATUS, &success);

	if (!success)
	{
		glGetProgramInfoLog(shader_program, 512, NULL, info_log);
		ft_putstr("SHADER PROGRAM LINKING ERROR: ");
		ft_putendl(info_log);
	}
	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);

//	float vertices[] = {
//    // positions          // colors           // texture coords
//     0.5000,  0.5f, 0.0f, //  1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
//     0.5f, -0.5f, 0.0f, //  0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
//    -0.5f, -0.5f, 0.0f, //  0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
//    -0.5f,  0.5f, 0.0f, //  1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
//};
//	unsigned int indices[] = {  // note that we start from 0!
//		0, 1, 3,   // first triangle
//		1, 2, 3    // second triangle
//	};

	unsigned int VBO;
	unsigned int VAO;
	unsigned int EBO;

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(e->mesh.verts), &e->mesh.verts[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(e->mesh.indices), &e->mesh.indices[0], GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * (sizeof(float)), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	while (!glfwWindowShouldClose(e->window)) 
	{
		process_inputs(e->window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shader_program);
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, e->data_size.indices , GL_UNSIGNED_INT, 0);
		//glDrawArrays(GL_TRIANGLES, 0, e->data_size.v_nb);

		glfwSwapBuffers(e->window);
		glfwPollEvents();
	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glDeleteProgram(shader_program);
}
