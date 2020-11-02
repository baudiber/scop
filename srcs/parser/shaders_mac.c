/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shaders_mac.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudibert <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 10:38:47 by baudibert         #+#    #+#             */
/*   Updated: 2020/11/02 19:56:58 by baudibert        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scop.h>

bool	read_shader(char *file_name, t_env *e, int shader)
{
	int		fd;
	char	*line;

	if ((fd = open(file_name, O_DIRECTORY)) >= 0)
		return (false);
	if ((fd = open(file_name, O_RDONLY)) < 0)
		return (false);
	while ((get_next_line(fd, &line)) > 0)
	{
		if (shader == 0)
			e->vertex_shader_src = ft_strjoinfree(e->vertex_shader_src,
				ft_strjoinfree(line, "\n", 1), 3);
		else if (shader == 1)
			e->fragment_shader_src = ft_strjoinfree(e->fragment_shader_src,
				ft_strjoinfree(line, "\n", 1), 3);
	}
	return (true);
}

char	*get_v_shader_file_name(t_env *e)
{
	char	*v_shader_file_name;

	v_shader_file_name = ft_strdup("srcs/shaders/vertex_shader");
	(void)e;
	if (e->mesh.has_vns && e->mesh.has_vts)
		v_shader_file_name = ft_strjoinfree(v_shader_file_name,
			"_normals_textures", 1);
	else if (e->mesh.has_vns)
		v_shader_file_name = ft_strjoinfree(v_shader_file_name, "_normals", 1);
	else if (e->mesh.has_vts)
		v_shader_file_name = ft_strjoinfree(v_shader_file_name, "_textures", 1);
	v_shader_file_name = ft_strjoinfree(v_shader_file_name, ".glsl", 1);
	return (v_shader_file_name);
}

char	*get_f_shader_file_name(t_env *e)
{
	char	*f_shader_file_name;

	(void)e;
	f_shader_file_name = ft_strdup("srcs/shaders/fragment_shader");
	if (e->mesh.has_vns && e->mesh.has_vts)
		f_shader_file_name = ft_strjoinfree(f_shader_file_name,
			"_normals_textures", 1);
	else if (e->mesh.has_vns)
		f_shader_file_name = ft_strjoinfree(f_shader_file_name, "_normals", 1);
	else if (e->mesh.has_vts)
		f_shader_file_name = ft_strjoinfree(f_shader_file_name, "_textures", 1);
	f_shader_file_name = ft_strjoinfree(f_shader_file_name, ".glsl", 1);
	return (f_shader_file_name);
}

void	parse_shaders(t_env *e)
{
	char	*v_shader_file_name;
	char	*f_shader_file_name;

	v_shader_file_name = get_v_shader_file_name(e);
	f_shader_file_name = get_f_shader_file_name(e);
	printf("loaded shaders: %s, %s\n", v_shader_file_name, f_shader_file_name);
	e->vertex_shader_src = ft_strdup("");
	e->fragment_shader_src = ft_strdup("");
	if (!read_shader(v_shader_file_name, e, 0))
		clean_exit("ERROR parsing vertex shader file");
	if (!read_shader(f_shader_file_name, e, 1))
		clean_exit("ERROR parsing fragment shader file");
	free(v_shader_file_name);
	free(f_shader_file_name);
}
