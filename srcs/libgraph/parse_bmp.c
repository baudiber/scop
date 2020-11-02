/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 14:54:07 by baudiber          #+#    #+#             */
/*   Updated: 2020/11/02 00:46:26 by baudibert        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libgraph.h"
#include "../includes/bmp.h"
#include <stdio.h>
#include <errno.h>

bool			parse_headers(int fd, int *w, int *h)
{
	ssize_t		ret;
	t_headers	headers;
	char        offset[200];

	ret = read(fd, &headers, sizeof(t_headers));
	if (headers.bits_per_pixel != 32 || headers.height < 0 || headers.width < 0)
		return (false);
	*w = headers.width;
	*h = headers.height;
	ret = read(fd, offset, headers.image_data_offset - sizeof(t_headers));
	return (true);
}

unsigned char	*parse_pixels(int total_pixels, int fd)
{
	t_image_data	id;
	unsigned char	*data;
	int				i;
	ssize_t			ret;

	if (!(data = (unsigned char*)malloc(sizeof(unsigned char) \
			* (total_pixels * 3) + 1)))
		return (NULL);
	i = 0;
	while (i < total_pixels)
	{
		ret = read(fd, &id, sizeof(id));
		data[i * 3] = id.r;
		data[(i * 3) + 1] = id.g;
		data[(i * 3) + 2] = id.b;
		i++;
	}
	data[i] = '\0';
	return (data);
}

unsigned char	*parse_pixels_alpha(int total_pixels, int fd)
{
	t_image_data	id;
	unsigned char	*data;
	int				i;
	ssize_t			ret;

	if (!(data = (unsigned char*)malloc(sizeof(unsigned char) \
			* (total_pixels * 4) + 1)))
		return (NULL);
	i = 0;
	while (i < total_pixels)
	{
		ret = read(fd, &id, sizeof(id));
		data[i * 4] = id.r;
		data[(i * 4) + 1] = id.g;
		data[(i * 4) + 2] = id.b;
		data[(i * 4) + 3] = id.a;
		i++;
	}
	data[i] = '\0';
	return (data);
}

/*
** 32 Bit BMP parsing
** Args:
** - file_path : path to the bmp file
** - w : will be filled with the img's width in pixels
** - h : will be filled with the img's height in pixels
** - alpha : 0 or RGB, != 0 for RGBA
** Return: img data in bytes
*/

unsigned char	*parse_bmp_32bit(const char *file_path, int *w, int *h, int alpha)
{
	int			fd;

	if ((fd = open(file_path, O_DIRECTORY)) >= 0)
		return (NULL);
	if ((fd = open(file_path, O_RDONLY)) < 0)
	{
    	fprintf( stderr, "errno is %d\n", errno );
		return (NULL);
	}
	if (!parse_headers(fd, w, h))
		return (NULL);
	if (alpha)
		return (parse_pixels_alpha(*w * *h, fd));
	else 
		return (parse_pixels(*w * *h, fd));
}
