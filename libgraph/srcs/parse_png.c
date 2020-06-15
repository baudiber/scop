/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_png.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 14:07:55 by baudiber          #+#    #+#             */
/*   Updated: 2020/06/15 14:19:03 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/libgraph.h"

const char * parse_png(char *file_path)
{
	int 	fd;


	if ((fd = open(file_path, O_DIRECTORY)) >= 0) 
		return NULL;
	if ((fd = open(file_path, O_RDONLY)) < 0)
		return NULL;

	return NULL;
}
