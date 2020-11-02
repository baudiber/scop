/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_faces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudibert <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:43:20 by baudibert         #+#    #+#             */
/*   Updated: 2020/11/02 22:42:24 by baudibert        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scop.h>

void	parse_face_line_vns(const char *line, t_list_iterators *iterators)
{
	t_f_lst		*new;
	int			i_nb;

	if (!(new = (t_f_lst *)malloc(sizeof(t_f_lst))))
		clean_exit("malloc error");
	i_nb = sscanf(line, "f %d//%d %d//%d %d//%d %d//%d", &new->indices[0],
			&new->normals[0], &new->indices[1], &new->normals[1],
			&new->indices[2], &new->normals[2], &new->indices[3],
			&new->normals[3]);
	if (i_nb != 6 && i_nb != 8)
		clean_exit("face vns sscanf error");
	new->quad = (i_nb == 6) ? false : true;
	iterators->i_nb += (i_nb == 6) ? 3 : 6;
	new->next = NULL;
	iterators->f_it->next = new;
	iterators->f_it = iterators->f_it->next;
}

void	parse_face_line_vts(const char *line, t_list_iterators *iterators)
{
	t_f_lst		*new;
	int			i_nb;

	if (!(new = (t_f_lst *)malloc(sizeof(t_f_lst))))
		clean_exit("malloc error");
	i_nb = sscanf(line, "f %d/%d %d/%d %d/%d %d/%d", &new->indices[0],
			&new->tex_cords[0], &new->indices[1], &new->tex_cords[1],
			&new->indices[2], &new->tex_cords[2], &new->indices[3],
			&new->tex_cords[3]);
	if (i_nb != 6 && i_nb != 8)
		clean_exit("face vts sscanf error");
	iterators->i_nb += (i_nb == 6) ? 3 : 6;
	new->quad = (i_nb == 6) ? false : true;
	new->next = NULL;
	iterators->f_it->next = new;
	iterators->f_it = iterators->f_it->next;
}

void	parse_face_line_vts_vns(const char *line, t_list_iterators *iterators)
{
	t_f_lst		*new;
	int			i_nb;

	if (!(new = (t_f_lst *)malloc(sizeof(t_f_lst))))
		clean_exit("malloc error");
	i_nb = sscanf(line, "f %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d",
		&new->indices[0], &new->tex_cords[0], &new->normals[0],
		&new->indices[1], &new->tex_cords[1], &new->normals[1],
		&new->indices[2], &new->tex_cords[2], &new->normals[2],
		&new->indices[3], &new->tex_cords[3], &new->normals[3]);
	if (i_nb != 9 && i_nb != 12)
		clean_exit("face vts vns sscanf error");
	new->quad = (i_nb == 9) ? false : true;
	iterators->i_nb += (i_nb == 9) ? 3 : 6;
	new->next = NULL;
	iterators->f_it->next = new;
	iterators->f_it = iterators->f_it->next;
}

void	parse_face_line(const char *line, t_list_iterators *iterators)
{
	t_f_lst		*new;
	int			i_nb;

	if (!(new = (t_f_lst *)malloc(sizeof(t_f_lst))))
		clean_exit("malloc error");
	i_nb = sscanf(line, "f %d %d %d %d", &new->indices[0], &new->indices[1],
		&new->indices[2], &new->indices[3]);
	if (i_nb != 3 && i_nb != 4)
		clean_exit("face sscanf error");
	new->quad = (i_nb == 3) ? false : true;
	iterators->i_nb += (i_nb == 3) ? 3 : 6;
	new->next = NULL;
	iterators->f_it->next = new;
	iterators->f_it = iterators->f_it->next;
}
