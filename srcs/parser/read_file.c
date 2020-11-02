/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudibert <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 15:11:36 by baudibert         #+#    #+#             */
/*   Updated: 2020/10/28 23:49:35 by baudibert        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scop.h>

static void read_lines(int fd, t_env *e)
{
    t_list_iterators    iterators;
    char    *line;

    init_iterator_struct(&iterators, e);
    while ((get_next_line(fd, &line)) > 0)
	{
        parse_line(line, &iterators, e);
        ft_strdel(&line);
	}
	e->data_size.indice_nb = iterators.i_nb;
	e->data_size.v_nb = iterators.v_nb;
	e->data_size.vt_nb = iterators.vt_nb;
	//e->data_size.vn_nb = iterators.vn_nb;
	if (!iterators.v_nb || !iterators.i_nb)
		clean_exit("file error, not enough vertice data to proceed\n");
}

bool    read_file(char *file_name, t_env *e)
{
    int     fd;

    if ((fd = open(file_name, O_DIRECTORY)) >= 0)
        return (false);
    if ((fd = open(file_name, O_RDONLY)) < 0)
        return (false);
    init_lists(e);
	read_lines(fd, e);
	malloc_buffers(e);
    return (true);
}
