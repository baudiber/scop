/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 15:05:14 by baudiber          #+#    #+#             */
/*   Updated: 2020/11/02 17:26:59 by baudibert        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scop.h>

void setup_buffers(t_env *e)
{
	glGenVertexArrays(1, &e->vao);
	glGenBuffers(1, &e->vbo);
	glGenBuffers(1, &e->ebo);
	glBindVertexArray(e->vao);
	glBindBuffer(GL_ARRAY_BUFFER, e->vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(t_vertex) * e->data_size.vert_nb, 
		&e->mesh.verts[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, e->ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int)
		* e->data_size.indice_nb , &e->mesh.index_buffer[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(t_vertex), (void*)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(t_vertex),
		(void*)sizeof(t_vec3));
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(t_vertex),
		(void*)(sizeof(t_vec3) * 2));
}

void generate_texture(t_env *e, int i, const char *path)
{
	int 			width;
	int 			height;
	unsigned char 	*texture_data;

	glBindTexture(GL_TEXTURE_2D, e->textures[i]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	texture_data = parse_bmp_32bit(path, &width, &height, 0);
	if (!texture_data)
		clean_exit("error loading texture");
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, texture_data);
	glGenerateMipmap(GL_TEXTURE_2D);
	free(texture_data);
}

void load_textures(t_env *e)
{
	glGenTextures(2, &e->textures[0]);
	generate_texture(e, 0, "./textures/wow.bmp");
	generate_texture(e, 1, "./textures/dirt.bmp");
	glUseProgram(e->shader_program);
	glUniform1i(glGetUniformLocation(e->shader_program, "texture1"), 0);
	glUniform1i(glGetUniformLocation(e->shader_program, "texture2"), 1);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, e->textures[0]);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, e->textures[1]);
}

void 	clear_gl_items(t_env *e)
{
	glDeleteVertexArrays(1, &e->vao);
	glDeleteBuffers(1, &e->vbo);
	glDeleteBuffers(1, &e->ebo);
	glDeleteProgram(e->shader_program);
	glDeleteTextures(1, &e->textures[0]);
	glDeleteTextures(1, &e->textures[1]);
}

void run(t_env *e)
{
	e->shader_program = compile_shaders(e);
	setup_buffers(e);
	load_textures(e);
	e->transition = 0.0f;
	e->camera = vec3(0.0f, 0.0f, -(e->data_size.max.y - e->data_size.min.y)
		* 3.0);
	e->projection = perspective(deg_to_rad(40.0f), WIN_W 
		/ (float)WIN_H, 0.1f, 100.0f);
	while (!glfwWindowShouldClose(e->window)) 
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		process_inputs(e->window);
		e->view = translate_mat4x4(identity_mat4x4(), e->camera);
		e->model = rotation_mat4x4(identity_mat4x4(), (float)glfwGetTime()
			* deg_to_rad(45.0f), vec3(0.0f, 1.0f, 0.0f));
		set_uniforms(e);
		if (e->shading >= 2)
			e->transition = (e->transition < 1.0f) ? e->transition + 0.003f 
				* glfwGetTime() : 1.0f;
		glDrawElements(GL_TRIANGLES, e->data_size.indice_nb, 
			GL_UNSIGNED_INT, 0);
		glfwSwapBuffers(e->window);
		glfwPollEvents();
	}
	clear_gl_items(e);
}
