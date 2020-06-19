/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 17:00:54 by baudiber          #+#    #+#             */
/*   Updated: 2020/06/19 13:53:42 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECS_H
# define VECS_H

typedef struct s_vec2 t_vec2;
typedef struct s_vec2_double t_vec2_double;
typedef struct s_vec2_int t_vec2_int;
typedef struct s_vec2_uint t_vec2_uint;
typedef struct __attribute__((__packed__))s_vec3 t_vec3;
typedef struct s_vec3_double t_vec3_double;
typedef struct s_vec3_int t_vec3_int;
typedef struct s_vec3_uint t_vec3_uint;
typedef struct s_vec4 t_vec4;
typedef struct s_vec4_double t_vec4_double;
typedef struct s_vec4_int t_vec4_int;
typedef struct s_vec4_uint t_vec4_uint;

struct s_vec2 {
	float x;
	float y;
};

struct s_vec2_double {
	double x;
	double y;
};

struct s_vec2_int {
	int x;
	int y;
};

struct s_vec2_uint {
	unsigned int x;
	unsigned int y;
};

struct s_vec3 {
	float x;
	float y;
	float z;
};

struct s_vec3_double {
	double x;
	double y;
	double z;
};

struct s_vec3_int {
	int x;
	int y;
	int z;
};

struct s_vec3_uint {
	unsigned int x;
	unsigned int y;
	unsigned int z;
};

struct s_vec4 {
	float x;
	float y;
	float z;
	float w;
};

struct s_vec4_double {
	double x;
	double y;
	double z;
	double w;
};

struct s_vec4_int {
	int x;
	int y;
	int z;
	int w;
};

struct s_vec4_uint {
	unsigned int x;
	unsigned int y;
	unsigned int z;
	unsigned int w;
};

#endif
