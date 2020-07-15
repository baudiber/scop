/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 12:31:15 by baudiber          #+#    #+#             */
/*   Updated: 2020/07/15 18:33:26 by baudiber         ###   ########.fr       */
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
# include <float.h>

#include <stdio.h>

typedef struct s_env    t_env;
typedef struct s_size   t_size;
typedef struct s_mesh 	t_mesh;
typedef struct s_vertex t_vertex;
typedef struct s_v_lst t_v_lst;
typedef struct s_f_lst t_f_lst;
typedef struct s_vt_lst t_vt_lst;
typedef struct s_vert_lst t_vert_lst;
typedef struct s_raw_data t_raw_data;


struct s_v_lst {
	t_vec3 		pos;
	t_v_lst 	*next;
};

struct s_f_lst {
	int 			indices[4];
	int 			tex_cords[4];
	unsigned int 	nb;
	t_f_lst 		*next;
};

struct s_vt_lst {
	t_vec2 			uv;
	t_vt_lst 		*next;
};

struct s_size
{
	unsigned int 	v_nb;
	unsigned int 	vt_nb;
	unsigned int 	indice_nb;
	unsigned int 	point_nb;
	unsigned int 	vert_nb;
	t_vec3 			max;
	t_vec3 			min;
};

struct s_vertex
{
	t_vec3 		pos;
	t_vec2 		text_coords;
	unsigned int index;
};

struct s_vert_lst {
	t_vertex  	v;
	t_vert_lst 	*next;
};

struct s_mesh
{
	t_vertex 		*verts;
	unsigned int 	*index_buffer;
	bool 			textured;
};

struct s_raw_data
{
	t_vec3 			*v;
	t_vec2 			*vt;
	t_vec2_int 		*indices;
};

struct s_env
{
	GLFWwindow 		*window;
	t_mesh 			mesh;
	t_size 			data_size;
	t_raw_data 		data;
	t_v_lst 		*v_lst;
	t_vt_lst 		*vt_lst;
	t_f_lst 		*f_lst;
	t_vert_lst 		*vert_lst;
	int 			shading;
};

void 	parse_obj(char *file_path, t_env *e);
void 	process_data(t_env *e);
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
