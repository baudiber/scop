/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 12:31:15 by baudiber          #+#    #+#             */
/*   Updated: 2020/06/09 20:59:21 by baudibert        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# include "../libft/libft.h"
# include <glad/glad.h> 
# include "GLFW/glfw3.h"
# include <stdbool.h>
# include <fcntl.h>

# define WIN_W 1024
# define WIN_H 768

typedef struct s_env    t_env;

struct s_env
{
	GLFWwindow* window;
	
};

bool    parse_file(char *file_name);
bool    init(t_env *e);

void    run(t_env *e);

void 	process_inputs(GLFWwindow *window);

#endif
