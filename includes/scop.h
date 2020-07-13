/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 12:31:15 by baudiber          #+#    #+#             */
/*   Updated: 2020/07/10 20:33:41 by baudibert        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# define WIN_W 1920
# define WIN_H 1080

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
typedef struct s_vertex t_vertex;
typedef struct s_vec_list t_vec_list;
typedef struct s_face_list t_face_list;

struct s_vec_list {
	float 		x;
	float 		y;
	float 		z;
	t_vec_list 	*next;
};

struct s_face_list {
	int 			indices[4];
	int 			tex_cords[4];
	unsigned int 	nb;
	t_face_list 	*next;
};

struct s_size
{
	unsigned int 	vec_nb;
	unsigned int 	indice_nb;
	unsigned int 	text_coord_nb;
	unsigned int 	point_nb;
	t_vec3 			max;
	t_vec3 			min;
};

struct s_mesh
{
	t_vec3 			*verts;
	unsigned int 	*indices;
	unsigned int 	*text_coords;
	bool 			textured;
};

struct s_env
{
	GLFWwindow 		*window;
	t_mesh 			mesh;
	t_size 			data_size;
	t_vec_list 		*vec_list;
	t_face_list 	*face_list;
	int 			shading;
};

bool    parse_file(char *file_name, t_env *e);
bool    init(t_env *e);
t_env					*get_env(void);

void    run(t_env *e);

void 	process_inputs(GLFWwindow *window);
t_vec4 vec4(float x, float y, float z);
t_vec3 vec3(float x, float y, float z);

t_mat4x4	scale_mat4x4(t_vec4 scale);
t_mat4x4	translate_mat4x4(t_mat4x4 mat, t_vec3 vec);
t_mat4x4	identity_mat4x4(void);
t_mat4x4 	perspective(float fovy, float aspect_ratio, float near, float far);
t_mat4x4 	rotation_mat4x4(t_mat4x4 src_mat, float angle, t_vec3 axis);
t_vec3 		normalize_vec3(t_vec3 v);

void 		print_mat(t_mat4x4 mat);
float 		deg_to_rad(float angle);
float 		rad_to_deg(float angle);

#endif
