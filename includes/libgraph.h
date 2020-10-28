/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgraph.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 14:08:25 by baudiber          #+#    #+#             */
/*   Updated: 2020/06/25 18:55:47 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGRAPH_H
# define LIBGRAPH_H

# include "vecs.h"
# include "matrix.h"

unsigned char	*parse_bmp_32bit(char *file_path, int *w, int *h, int alpha);
t_mat4x4 		mult_4x4mat(t_mat4x4 m1, t_mat4x4 m2);
t_vec4 			mult_mat4x4(t_vec4 v, t_mat4x4 mat);
t_mat4x4 		scale_4x4mat(t_mat4x4 m1, t_vec3 scale);

#endif
