/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 14:54:07 by baudiber          #+#    #+#             */
/*   Updated: 2020/06/15 17:12:11 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/libgraph.h"
# include "../includes/bmp.h"
# include <stdio.h>

const unsigned char *parse_bmp(char *file_path) 
{
	int 	fd;
	t_file_header fh;
	t_image_header ih;
	int 	total_pixels;
	int 	i;
	t_image_data id;
	unsigned char 	*data;

	if ((fd = open(file_path, O_DIRECTORY)) >= 0) 
		return NULL;
	if ((fd = open(file_path, O_RDONLY)) < 0)
		return NULL;
	ssize_t ret = read(fd, &fh, sizeof(fh));
	//printf("%lu %d %c %c %d\n",ret, fh.f_size, fh.b, fh.m, fh.image_data_offset);
	ret = read(fd, &ih, sizeof(ih));
	//printf("%lu %d %d %d\n",ret, ih.width, ih.height, ih.bits_per_pixel);
	total_pixels = ih.width * ih.height;
	if (!(data = (unsigned char*)malloc(sizeof(unsigned char) * (total_pixels * 3) + 1)) || ih.bits_per_pixel != 32)
	{
		printf("bbp: %d", ih.bits_per_pixel);
		return (NULL);
	}

	i = 0;
	while (i < total_pixels)
	{
		ret = read(fd, &id, sizeof(id));
		data[i * 3] = id.r;
		data[(i * 3) + 1] = id.g;
		data[(i * 3) + 2] = id.b;
		//printf("%d %d %d\n", id.r, id.g, id.b);
		i++;
	}
	data[i] = '\0';

	if ((fd = close(fd)) < 0)
		return NULL;

	return data;
}
