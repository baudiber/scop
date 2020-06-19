/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 15:05:14 by baudiber          #+#    #+#             */
/*   Updated: 2020/06/19 16:13:48 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"

const char *vertexShaderSource = "#version 410 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "out vec4 myColor;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos, 1.0);\n"
	" 	myColor = vec4(1.0 * aPos.z, 1.0 * aPos.z, 1.0 * aPos.z, 1.0);\n"
    "}\0";

const char *fragmentShaderSource = "#version 410 core\n"
 	"in vec4 myColor;\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = myColor;\n"
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

t_vec4 vec4(float x, float y, float z)
{
	t_vec4 ret;

	ret.x = x;
	ret.y = y;
	ret.z = z;
	ret.w = 1.0f;
	return (ret);
}

t_vec3 vec3(float x, float y, float z)
{
	t_vec3 ret;

	ret.x = x;
	ret.y = y;
	ret.z = z;
	return (ret);
}

void run(t_env *e)
{
//	unsigned int i = 0;
//	while (i < e->data_size.points)
//	{
//		printf("%f\t%f\t%f\n", e->mesh.verts[i], e->mesh.verts[i + 1], e->mesh.verts[i +2]);
//		i += 3;
//	}
//	i = 0;
//	while (i < e->data_size.indices)
//	{
//		printf("%d\t%d\t%d\n", e->mesh.indices[i], e->mesh.indices[i + 1], e->mesh.indices[i +2]);
//		i += 3;
//	}
 	t_mat4x4 	model;
 	t_mat4x4 	view;

	model = identity_mat4x4();
	//view = identity_mat4x4();

	view = scale_mat4x4(vec4(0.0f, 0.0f, -3.0f));


	unsigned int shader_program;
	shader_program = compile_shaders();

	printf("indicenb %d\n", e->data_size.indices);
	printf("pointnb %d\n", e->data_size.points);

	unsigned int VBO;
	unsigned int VAO;
	unsigned int EBO;

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(t_vec3) * (e->data_size.points / 3), e->mesh.vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * e->data_size.indices, e->mesh.indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * (sizeof(float)), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);


	//glEnable(GL_DEPTH_TEST);

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
