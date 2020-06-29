/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 12:31:15 by baudiber          #+#    #+#             */
/*   Updated: 2020/06/29 20:20:03 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# define WIN_W 1024
# define WIN_H 768

# include "../libft/libft.h"
# include "../libgraph/includes/libgraph.h"
# include <glad/glad.h> 
# include "GLFW/glfw3.h"
# include <stdbool.h>
# include <fcntl.h>
# include <math.h>

#include <stdio.h>

typedef struct s_env    t_env;
typedef struct s_size   t_size;
typedef struct s_mesh 	t_mesh;

struct s_size
{
	unsigned int v_nb;
	unsigned int f_nb;
	unsigned int indices;
	unsigned int points;
};

struct s_mesh
{
	t_vec3	*vertices;
	int		**faces;
	float 	*verts;
	unsigned int 	*indices;
};

struct s_env
{
	GLFWwindow* window;
	t_mesh 		mesh;
	t_size 		data_size;
};

bool    parse_file(char *file_name, t_env *e);
bool    init(t_env *e);

void    run(t_env *e);

void 	process_inputs(GLFWwindow *window);

t_mat4x4	scale_mat4x4(t_vec4 scale);
t_mat4x4	translate_mat4x4(t_mat4x4 mat, t_vec3 vec);
t_mat4x4	identity_mat4x4(void);
t_mat4x4 	perspective(float fovy, float aspect_ratio, float near, float far);
t_mat4x4 	rotation_mat4x4(t_mat4x4 src_mat, float angle, t_vec3 axis);

void 		print_mat(t_mat4x4 mat);
float 		deg_to_rad(float angle);
float 		rad_to_deg(float angle);

#endif
