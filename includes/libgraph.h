/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgraph.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 14:08:25 by baudiber          #+#    #+#             */
/*   Updated: 2020/11/02 17:44:09 by baudibert        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGRAPH_H
# define LIBGRAPH_H

# include <vecs.h>
# include <matrix.h>
# include <stdbool.h>
# include <stdio.h>
# include <math.h>
# include <float.h>

bool            float_cmp(float float1, float float2);
unsigned char	*parse_bmp_32bit(const char *file_path, int *w, int *h, int alpha);
t_mat4x4 		mult_4x4mat(t_mat4x4 m1, t_mat4x4 m2);

#endif
