/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 15:05:14 by baudiber          #+#    #+#             */
/*   Updated: 2020/07/24 11:48:23 by baudibert        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"

unsigned int compile_vertex_shader(t_env *e) {
	unsigned int vertex_shader;
	int success;
	char info_log[512];

	vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex_shader, 1, (const char* const *)&e->vertex_shader_src, NULL);
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

unsigned int compile_fragment_shader(t_env *e) {
	unsigned int fragment_shader;
	int success;
	char info_log[512];

	fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment_shader, 1, (const char* const*)&e->fragment_shader_src, NULL);
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

unsigned int compile_shaders(t_env *e) {
	unsigned int vertex_shader;
	unsigned int fragment_shader;
	unsigned int shader_program;

	vertex_shader = compile_vertex_shader(e);
	fragment_shader = compile_fragment_shader(e);
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

t_vec2 vec2(float x, float y)
{
	t_vec2 ret;

	ret.x = x;
	ret.y = y;
	return (ret);
}

void run(t_env *e)
{
	unsigned int shader_program;
	shader_program = compile_shaders(e);

//	printf("indicenb %d\n", e->data_size.indices);
//	printf("pointnb %d\n", e->data_size.points);
//	printf("pointnb %d\n", e->data_size.points);

//	for (unsigned int i = 0; i < e->data_size.indice_nb; i++)
//	{
//		printf("%f %f %f    %f %f\n", e->mesh.verts[e->mesh.index_buffer[i]].pos.x, e->mesh.verts[e->mesh.index_buffer[i]].pos.y, e->mesh.verts[e->mesh.index_buffer[i]].pos.z, e->mesh.verts[e->mesh.index_buffer[i]].text_coords.x, e->mesh.verts[e->mesh.index_buffer[i]].text_coords.y);
//	}
//	//for (unsigned int i = 0; i < e->data_size.indice_nb;i++)
	//{
		//printf("%d\n", e->mesh.index_buffer[i]);
	//}


	unsigned int VBO;
	unsigned int model_VAO;
	unsigned int EBO;

	glGenVertexArrays(1, &model_VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	glBindVertexArray(model_VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(t_vertex) * e->data_size.vert_nb , &e->mesh.verts[0], GL_STATIC_DRAW);
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * e->data_size.indice_nb , &e->mesh.index_buffer[0], GL_STATIC_DRAW);

	// position attribute
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(t_vertex), (void*)0);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(t_vertex), (void*)sizeof(t_vec3));

	glBindVertexArray(0);

	unsigned int textures[2];
	glGenTextures(2, &textures[0]);
	glBindTexture(GL_TEXTURE_2D, textures[0]);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height;
	unsigned char *texture1_data = parse_bmp_32bit("./textures/wow.bmp", &width, &height, 0);
	if (texture1_data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, texture1_data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else 
	{
		ft_putendl("error loading texture");
		exit(0);
	}
	free(texture1_data);

	glBindTexture(GL_TEXTURE_2D, textures[1]);
	unsigned char *texture2_data = parse_bmp_32bit("./textures/dirt.bmp", &width, &height, 0);
	if (texture2_data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, texture2_data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else 
	{
		ft_putendl("error loading texture");
		exit(0);
	}
	free(texture2_data);

	glUseProgram(shader_program);
	glUniform1i(glGetUniformLocation(shader_program, "texture1"), 0);
	glUniform1i(glGetUniformLocation(shader_program, "texture2"), 1);
	
//	unsigned int light_VAO;
//	glGenVertexArrays(1, &light_VAO);
//	glBindVertexArray(light_VAO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	t_mat4x4 	model;
 	t_mat4x4 	view;
 	t_mat4x4 	projection;

	float 		transition;
	e->camera = vec3(0.0f, 0.0f, -(e->data_size.max.z - e->data_size.min.z) * 0.6f - 1);
	projection = perspective(deg_to_rad(50.0f), WIN_W / (float)WIN_H, 0.1f, 1000.0f);

	while (!glfwWindowShouldClose(e->window)) 
	{
		process_inputs(e->window);

		glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		view = identity_mat4x4();
		view = translate_mat4x4(view, e->camera);
		t_mat4x4    scale;
		scale = identity_mat4x4();
		scale = scale_4x4mat(scale, vec3(0.4f, 0.4f, 0.4f));
		model = identity_mat4x4();
		model = mult_4x4mat(scale, model);
		model = translate_mat4x4(model, vec3(-(e->data_size.max.x + e->data_size.min.x) / 2.0f, -(e->data_size.max.y + e->data_size.min.y) / 2.0f, -(e->data_size.max.z + e->data_size.min.z) / 2.0f));
		model = rotation_mat4x4(model, (float)glfwGetTime() * deg_to_rad(45.0f), vec3(0.0f, 1.0f, 0.0f));
		int shadingLoc = glGetUniformLocation(shader_program, "shading");
		int modelLoc = glGetUniformLocation(shader_program, "model");
		int viewloc = glGetUniformLocation(shader_program, "view");
		int projLoc = glGetUniformLocation(shader_program, "projection");
		int transitionLoc = glGetUniformLocation(shader_program, "transition");
		glUniform1i(shadingLoc, e->shading);
		if (e->shading == 2)
		{
			if (transition < 1.0f)
				transition += 0.003f * glfwGetTime();
			else
				transition = 1.0f;
		}
		else 
			transition = 0.0f;

		glUniform1f(transitionLoc, transition);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, &model.m[0][0]);
		glUniformMatrix4fv(viewloc, 1, GL_FALSE, &view.m[0][0]);
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, &projection.m[0][0]);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, textures[0]);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, textures[1]);
		glUseProgram(shader_program);
		glBindVertexArray(model_VAO);
		glDrawElements(GL_TRIANGLES, e->data_size.indice_nb , GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(e->window);
		glfwPollEvents();
	}

	glDeleteVertexArrays(1, &model_VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glDeleteProgram(shader_program);
}
