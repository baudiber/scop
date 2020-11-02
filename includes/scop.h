/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 12:31:15 by baudiber          #+#    #+#             */
/*   Updated: 2020/11/02 16:15:10 by baudibert        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# define WIN_W 800
# define WIN_H 600

# include <libft.h>
# include <libgraph.h>
# include <GL/glew.h>
# include <GLFW/glfw3.h>
# include <stdbool.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_env    			t_env;
typedef struct s_size   			t_size;
typedef struct s_mesh 				t_mesh;
typedef struct s_vertex 			t_vertex;
typedef struct s_v_lst 				t_v_lst;
typedef struct s_f_lst 				t_f_lst;
typedef struct s_vt_lst 			t_vt_lst;
typedef struct s_vn_lst 			t_vn_lst;
typedef struct s_vert_lst 			t_vert_lst;
typedef struct s_raw_data 			t_raw_data;
typedef struct s_list_iterators 	t_list_iterators;


struct s_v_lst {
	t_vec3 			pos;
	t_v_lst 		*next;
};

struct s_f_lst {
	int 			indices[4];
	int 			normals[4];
	int 			tex_cords[4];
	bool 			quad;
	t_f_lst 		*next;
};

struct s_vn_lst {
    t_vec3 			normals;
    t_vn_lst 		*next;
};

struct s_vt_lst {
	t_vec2 			uv;
	t_vt_lst 		*next;
};

struct s_size
{
	unsigned int 	v_nb;
	unsigned int 	vn_nb;
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
	t_vec3 		normal;
	t_vec2 		text_coords;
	unsigned int index;
};

struct s_vert_lst {
	t_vertex  	v;
	t_vert_lst 	*next;
};

struct s_list_iterators {
    t_v_lst     *v_it;
    t_f_lst     *f_it;
    t_vt_lst    *vt_it;
    t_vn_lst    *vn_it;
    int         v_nb;
    int         vt_nb;
    int         vn_nb;
    int         i_nb;
};

struct s_mesh
{
	t_vertex 		*verts;
	unsigned int 	*index_buffer;
	bool 			has_vts;
	bool 			has_vns;
};

struct s_raw_data
{
	t_vec3 			*v;
	t_vec3 			*vn;
	t_vec3_int 		*indices;
	t_vec2 			*vt;
};

struct s_env
{
	GLFWwindow 		*window;
	t_mesh 			mesh;
	float 			transition;
	t_size 			data_size;
	t_vec3 			camera;
	t_raw_data 		data;
	t_v_lst 		*v_lst;
	t_vt_lst 		*vt_lst;
	t_vn_lst 		*vn_lst;
	t_f_lst 		*f_lst;
	t_vert_lst 		*vert_lst;
	char 			*vertex_shader_src;
	char 			*fragment_shader_src;
	int 			shading;

    unsigned int    textures[2];
    unsigned int    vao;
	unsigned int    vbo;
	unsigned int    ebo;
	unsigned int    shader_program;
	t_mat4x4        model;
	t_mat4x4        view;
	t_mat4x4        projection;
    t_mat4x4        scale;
};

void 	scop(char *av1);
void 	init_gl_version(void);
void    parse_line(char *line, t_list_iterators *iterators, t_env *e);
void 	clean_exit(const char *msg);
void 	parse_obj(char *file_path, t_env *e);
void    parse_face_line(const char *line, t_list_iterators *iterators);
void    parse_face_line_vts(const char *line, t_list_iterators *iterators);
void    parse_face_line_vns(const char *line, t_list_iterators *iterators);
void    parse_face_line_vts_vns(const char *line, t_list_iterators *iterators);
void 	process_data(t_env *e);
void 	normalize_mesh(t_env *e);
void 	get_min_max(t_env *e);
void 	set_uniforms(t_env *e);
unsigned int compile_shaders(t_env *e);
void    init_iterator_struct(t_list_iterators *iterators, t_env *e);
bool        init_lists(t_env *e);
void 		malloc_buffers(t_env *e);
int 	vert_already_exists(t_vertex vert, t_env *e);
void 	create_vert_data(t_env *e);
void free_vert_lst(t_env *e);
void 	create_vert_lst(t_env *e);
void 		free_lists(t_env *e);
void 		process_vdata(t_env *e);
void 		process_vtdata(t_env *e);
void 		process_vndata(t_env *e);
void 		process_fdata(t_env *e);
void 	malloc_vertices(t_env *e);
void    free_raw_data(t_env *e);
void 	malloc_vert_list(t_env *e);
bool    read_file(char *file_name, t_env *e);
void    init(t_env *e);
t_env	*get_env(void);
void    run(t_env *e);
void 	process_inputs(GLFWwindow *window);
t_vec2  vec2(float x, float y);
t_vec4  vec4(float x, float y, float z);
t_vec3  vec3(float x, float y, float z);
void 	parse_shaders(t_env *e);
t_mat4x4	translate_mat4x4(t_mat4x4 mat, t_vec3 vec);
t_mat4x4	identity_mat4x4(void);
t_mat4x4 	perspective(float fovy, float aspect_ratio, float near, float far);
t_mat4x4 	rotation_mat4x4(t_mat4x4 src_mat, float angle, t_vec3 axis);
t_vec3 		normalize_vec3(t_vec3 v);
float 		deg_to_rad(float angle);

#endif
