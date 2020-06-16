/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 14:54:07 by baudiber          #+#    #+#             */
/*   Updated: 2020/06/16 14:24:21 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libgraph.h"
#include "../includes/bmp.h"

bool			parse_headers(int fd, int *w, int *h)
{
	ssize_t		ret;
	t_headers	headers;

	ret = read(fd, &headers, sizeof(t_headers));
	if (headers.bits_per_pixel != 32)
		return (false);
	*w = headers.width;
	*h = headers.height;
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

/*
** 32 Bit BMP parsing
** Args:
** - file_path : path to the bmp file
** - w : will be filled with the img's width in pixels
** - h : will be filled with the img's height in pixels
** Return: img data in bytes as RGB
*/

unsigned char	*parse_bmp_32bit(char *file_path, int *w, int *h)
{
	int			fd;

	if ((fd = open(file_path, O_DIRECTORY)) >= 0)
		return (NULL);
	if ((fd = open(file_path, O_RDONLY)) < 0)
		return (NULL);
	if (!parse_headers(fd, w, h))
		return (NULL);
	return (parse_pixels(*w * *h, fd));
}
