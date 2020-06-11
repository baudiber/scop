/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_exo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 15:05:14 by baudiber          #+#    #+#             */
/*   Updated: 2020/06/11 14:31:49 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"

const char *vertexShaderSource = "#version 410 core\nlayout (location = 0) in vec3 aPos;\nvoid main()\n{\n   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n}\0";

const char *fragmentShaderSource = "#version 410 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";

const char *fragmentShaderSource_yellow = "#version 410 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.8f, 0.2f, 1.0f);\n"
    "}\n\0";

unsigned int compile_vertex_shader() {
	unsigned int vertex_shader;
	int success;
	char info_log[512];

	vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex_shader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertex_shader);
	glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertex_shader, 512, NULL, info_log);
		ft_putstr("VERTEX SHADER COMPILE ERROR: ");
		ft_putendl(info_log);
		exit(0);
	}
	return vertex_shader;
}

unsigned int compile_fragment_shader() {
	unsigned int fragment_shader;
	int success;
	char info_log[512];

	fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment_shader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragment_shader);
	glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragment_shader, 512, NULL, info_log);
		ft_putstr("FRAGMENT SHADER COMPILE ERROR: ");
		ft_putendl(info_log);
		exit(0);
	}
	return fragment_shader;
}

unsigned int compile_fragment_shader_yellow() {
	unsigned int fragment_shader;
	int success;
	char info_log[512];

	fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment_shader, 1, &fragmentShaderSource_yellow, NULL);
	glCompileShader(fragment_shader);
	glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragment_shader, 512, NULL, info_log);
		ft_putstr("FRAGMENT SHADER COMPILE ERROR: ");
		ft_putendl(info_log);
		exit(0);
	}
	return fragment_shader;
}

unsigned int compile_shader_program(unsigned int vertex_shader, unsigned int fragment_shader) {
	unsigned int shader_program;
	int success;
	char info_log[512];

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
		exit(0);
	}
	return shader_program;
}

unsigned int compile_shaders() {
	unsigned int vertex_shader;
	unsigned int fragment_shader;
	unsigned int shader_program;

	vertex_shader = compile_vertex_shader();
	fragment_shader = compile_fragment_shader();
	shader_program = compile_shader_program(vertex_shader, fragment_shader);
	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);

	return shader_program;
}

unsigned int compile_shaders_y() {
	unsigned int vertex_shader;
	unsigned int fragment_shader;
	unsigned int shader_program;

	vertex_shader = compile_vertex_shader();
	fragment_shader = compile_fragment_shader_yellow();
	shader_program = compile_shader_program(vertex_shader, fragment_shader);
	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);

	return shader_program;
}

void run(t_env *e)
{
	float triangles[2][9] = {
	{
		0.5f, -0.5f, 0.0f,  // bottom right
		-0.5f, -0.5f, 0.0f,  // bottom left
		-0.5f,  0.5f, 0.0f   // top left 
	}, 
	{
		0.5f,  0.5f, 0.0f,  // top right
		0.5f, -0.5f, 0.0f,  // bottom right
		-0.5f,  0.5f, 0.0f,   // top left 
	}};


	//the Vertex Buffer Object stores vertices in the gpu's memory
	//VERTEX BUFFER's type is GL_ARRAY_BUFFER
	unsigned int VBO[2];
	//unsigned int VBO;
	//Vertex Array Object stores vertex attributes and which VBO to use
	unsigned int VAO[2];
	//unsigned int VAO2;
	//Element Buffer Object stores the indices of which vertex to draw when
	unsigned int shader_program;
	unsigned int shader_program_y;

	shader_program = compile_shaders();
	shader_program_y = compile_shaders_y();

	glGenVertexArrays(2, VAO);
	glGenBuffers(2, VBO);
	int i =0;
	while (i < 2) {
		glBindVertexArray(VAO[i]);

		glBindBuffer(GL_ARRAY_BUFFER, VBO[i]);
		//after ^ any call on target GL_ARRAY_BUFFER will config VBO
		// v copies vertex data to the buffer
		// glBufferData fn copies data to the currently bound buffer
		glBufferData(GL_ARRAY_BUFFER, sizeof(triangles[i]), triangles[i], GL_STATIC_DRAW);
		//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		//here we tell GL how to interpret the vertex data
		//first arg n(0) is location n(0) in vertex shader
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		//this v enables this ^
		glEnableVertexAttribArray(0);
		// 0 is the VBO id (since it's the first we enable?)

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
		//unbind VBO
		i++;
	}
	

	while (!glfwWindowShouldClose(e->window)) 
	{
		process_inputs(e->window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shader_program);
		//binding VAO to draw object
		int i = 0;
		while (i < 2) {
			glBindVertexArray(VAO[i]);
			glDrawArrays(GL_TRIANGLES, 0, 3);
			glUseProgram(shader_program_y);
			i++;
		}

		glfwSwapBuffers(e->window);
		glfwPollEvents();
	}

	glDeleteVertexArrays(2, VAO);
	glDeleteBuffers(2, VBO);
	//glDeleteBuffers(1, &EBO);
	glDeleteProgram(shader_program);
}
