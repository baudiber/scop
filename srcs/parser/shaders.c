/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shaders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudibert <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 10:38:47 by baudibert         #+#    #+#             */
/*   Updated: 2020/07/24 11:56:26 by baudibert        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"

bool    read_shader(char *file_name, t_env *e, int shader)
{
    int     fd;
	char 	*line;

    if ((fd = open(file_name, O_DIRECTORY)) >= 0)
        return (false);
    if ((fd = open(file_name, O_RDONLY)) < 0)
        return (false);
    while ((get_next_line(fd, &line)) > 0)
	{
		if (shader == 0)
			e->vertex_shader_src = ft_strjoinfree(e->vertex_shader_src, ft_strjoinfree(line, "\n", 1), 3);
		else if (shader == 1)
			e->fragment_shader_src = ft_strjoinfree(e->fragment_shader_src, ft_strjoinfree(line, "\n", 1), 3);
	}
	return (true);
}

void 	parse_shaders(t_env *e)
{
	e->vertex_shader_src = ft_strdup("");
	e->fragment_shader_src = ft_strdup("");
	if (!read_shader("srcs/shaders/vertex_shader.glsl", e, 0))
	{
        ft_putendl("ERROR parsing vertex shader file");
		exit(-1);
	}
	if (!read_shader("srcs/shaders/fragment_shader.glsl", e, 1))
	{
        ft_putendl("ERROR parsing fragment shader file");
		exit(-1);
	}
}
