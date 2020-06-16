/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 12:31:15 by baudiber          #+#    #+#             */
/*   Updated: 2020/06/16 16:50:25 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

//# define STB_IMAGE_IMPLEMENTATION
# define WIN_W 1024
# define WIN_H 768

# include "../libft/libft.h"
# include "../libgraph/includes/libgraph.h"
# include <glad/glad.h> 
# include "GLFW/glfw3.h"
# include <stdbool.h>
# include <fcntl.h>
# include <math.h>
//# include "stb_image.h"


typedef struct s_env    t_env;
typedef struct s_size    t_size;

struct s_env
{
	GLFWwindow* window;
	
};

struct s_size
{
	int v_nb;
	int f_nb;
};

struct s_mesh
{
	
};

bool    parse_file(char *file_name);
bool    init(t_env *e);

void    run(t_env *e);

void 	process_inputs(GLFWwindow *window);

#endif
