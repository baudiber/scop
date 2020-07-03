/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 15:05:14 by baudiber          #+#    #+#             */
/*   Updated: 2020/07/03 17:17:35 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"

const char *vertexShaderSource = "#version 410 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "layout (location = 1) in vec4 myColor;\n"

	"uniform mat4 model;\n"
	"uniform mat4 view;\n"
	"uniform mat4 projection;\n"
	"flat out vec4 color;\n"

    "void main()\n"
    "{\n"
    "   gl_Position = projection * view * model * vec4(aPos, 1.0);\n"
    //"   color = myColor;\n"
	" 	color = vec4( aPos.x * 0.4, aPos.y * 0.4 , aPos.z * 0.4  , 1.0);\n"
    "}\0";

const char *fragmentShaderSource = "#version 410 core\n"
	"out vec4 FragColor;\n"

	"flat in vec4 color;\n"
//	"uniform vec3 objectColor;\n"
//	"uniform vec3 lightColor;\n"

    "void main()\n"
    "{\n"
    "   FragColor = color;\n"
    //"   FragColor = vec4(lightColor * objectColor, 1.0);\n"
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
	printf("X max min %f %f\n", e->data_size.max.x ,e->data_size.min.x);
	printf("X offset %f \n", -(e->data_size.max.x + e->data_size.min.x));
	printf("Y max min %f %f\n", e->data_size.max.y ,e->data_size.min.y);
	printf("Z max min %f %f\n", e->data_size.max.z ,e->data_size.min.z);
	//view = translate_mat4x4(view, vec3(-(e->data_size.max.x + e->data_size.min.x), -(e->data_size.max.y + e->data_size.min.y) , (-(e->data_size.max.z - e->data_size.min.z) - 0.1) * 2));


	unsigned int shader_program;
	shader_program = compile_shaders();

	printf("indicenb %d\n", e->data_size.indices);
	printf("pointnb %d\n", e->data_size.points);

	unsigned int VBO;
	unsigned int model_VAO;
	unsigned int EBO;

	glGenVertexArrays(1, &model_VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	glBindVertexArray(model_VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(t_vertex) * e->data_size.v_nb , &e->mesh.vertices[0], GL_STATIC_DRAW);
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * e->data_size.indices , &e->mesh.indices[0], GL_STATIC_DRAW);

	// position attribute
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_TRUE, sizeof(t_vertex), (void*)0);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_TRUE, sizeof(t_vertex), (void*)sizeof(t_vec3));

	glBindVertexArray(0);
//	unsigned int light_VAO;
//	glGenVertexArrays(1, &light_VAO);
//	glBindVertexArray(light_VAO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glEnable(GL_DEPTH_TEST);
	

 	t_mat4x4 	model;
 	t_mat4x4 	view;
 	t_mat4x4 	projection;


	view = identity_mat4x4();
	//view = translate_mat4x4(view, vec3(0.0f, 0.0f, -3.0f)) ;
	view = translate_mat4x4(view, vec3(-(e->data_size.max.x + e->data_size.min.x), (e->data_size.max.y + e->data_size.min.y), -(e->data_size.max.z + e->data_size.min.z)));
	projection = perspective(deg_to_rad(50.0f), WIN_W / (float)WIN_H, 0.1f, 100.0f);

	while (!glfwWindowShouldClose(e->window)) 
	{
		process_inputs(e->window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//t_mat4x4    scale;
		//scale = identity_mat4x4();
		//scale = scale_4x4mat(scale, vec3(0.3f, 0.3f, 0.3f));
		//model = mult_4x4mat(scale, model);
		model = identity_mat4x4();
		model = translate_mat4x4(model, vec3(-(e->data_size.max.x + e->data_size.min.x) + 1, -(e->data_size.max.y + e->data_size.min.y), -(e->data_size.max.z + e->data_size.min.z)));
		//model = rotation_mat4x4(model, deg_to_rad(-90.0f), vec3(0.0f, 1.0f, 0.0f));
		model = rotation_mat4x4(model, (float)glfwGetTime() * deg_to_rad(45.0f), vec3(0.0f, 1.0f, 0.0f));
		//print_mat(model);
	//	printf("---------\n");
		int modelLoc = glGetUniformLocation(shader_program, "model");
		int viewloc = glGetUniformLocation(shader_program, "view");
		int projLoc = glGetUniformLocation(shader_program, "projection");
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, &model.m[0][0]);
		glUniformMatrix4fv(viewloc, 1, GL_FALSE, &view.m[0][0]);
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, &projection.m[0][0]);

		glUseProgram(shader_program);
		glBindVertexArray(model_VAO);
		glDrawElements(GL_TRIANGLES, e->data_size.indices , GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(e->window);
		glfwPollEvents();
	}

	glDeleteVertexArrays(1, &model_VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glDeleteProgram(shader_program);
}
