/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 14:55:08 by baudiber          #+#    #+#             */
/*   Updated: 2020/06/15 16:19:46 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_H
# define BMP_H

# include <stdint.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

typedef struct __attribute__((__packed__)) s_file_header	t_file_header;
typedef struct __attribute__((__packed__)) s_image_header	t_image_header;
typedef struct __attribute__((__packed__)) s_image_data	t_image_data;

struct	s_file_header {
	unsigned char	b;
	unsigned char	m;
	unsigned int	f_size;
	uint16_t		unused1;
	uint16_t		unused2;
	unsigned int	image_data_offset;
};

struct	s_image_header {
	unsigned int	image_header_size;
	unsigned int	width;
	unsigned int	height;
	uint16_t		planes;
	uint16_t		bits_per_pixel;
	unsigned int	compression;
	unsigned int	image_size;
	unsigned int	x_pixels_per_meter;
	unsigned int	y_pixels_per_meter;
	unsigned int	nb_color_maps;
	unsigned int	nb_colors;
};

struct	s_image_data {
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	z;
};

#endif
