/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shaders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudibert <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:33:18 by baudibert         #+#    #+#             */
/*   Updated: 2020/11/02 18:43:55 by baudibert        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scop.h>

unsigned int	compile_vertex_shader(t_env *e)
{
	unsigned int	vertex_shader;
	int				success;
	char			info_log[512];

	vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex_shader, 1, (const char*const*)&e->vertex_shader_src,
		NULL);
	glCompileShader(vertex_shader);
	glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertex_shader, 512, NULL, info_log);
		ft_putstr("VERTEX SHADER COMPILE ERROR: ");
		ft_putendl(info_log);
		exit(0);
	}
	return (vertex_shader);
}

unsigned int	compile_fragment_shader(t_env *e)
{
	unsigned int	fragment_shader;
	int				success;
	char			info_log[512];

	fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment_shader, 1,
		(const char*const*)&e->fragment_shader_src, NULL);
	glCompileShader(fragment_shader);
	glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragment_shader, 512, NULL, info_log);
		ft_putstr("FRAGMENT SHADER COMPILE ERROR: ");
		ft_putendl(info_log);
		exit(0);
	}
	return (fragment_shader);
}

unsigned int	compile_shader_program(unsigned int vertex_shader,
	unsigned int fragment_shader)
{
	unsigned int	shader_program;
	int				success;
	char			info_log[512];

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
	return (shader_program);
}

unsigned int	compile_shaders(t_env *e)
{
	unsigned int	vertex_shader;
	unsigned int	fragment_shader;
	unsigned int	shader_program;

	vertex_shader = compile_vertex_shader(e);
	fragment_shader = compile_fragment_shader(e);
	shader_program = compile_shader_program(vertex_shader, fragment_shader);
	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);
	return (shader_program);
}

void			set_uniforms(t_env *e)
{
	int		shading_loc;
	int		model_loc;
	int		view_loc;
	int		proj_loc;
	int		transition_loc;

	shading_loc = glGetUniformLocation(e->shader_program, "shading");
	model_loc = glGetUniformLocation(e->shader_program, "model");
	view_loc = glGetUniformLocation(e->shader_program, "view");
	proj_loc = glGetUniformLocation(e->shader_program, "projection");
	transition_loc = glGetUniformLocation(e->shader_program, "transition");
	glUniform1i(shading_loc, e->shading);
	glUniform1f(transition_loc, e->transition);
	glUniformMatrix4fv(model_loc, 1, GL_FALSE, &e->model.m[0][0]);
	glUniformMatrix4fv(view_loc, 1, GL_FALSE, &e->view.m[0][0]);
	glUniformMatrix4fv(proj_loc, 1, GL_FALSE, &e->projection.m[0][0]);
}