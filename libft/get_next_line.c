/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 17:10:09 by baudiber          #+#    #+#             */
/*   Updated: 2018/04/10 10:48:25 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_check(char **str, char **line)
{
	char	*bsn;

	bsn = ft_strchr(*str, '\n');
	*line = ft_strchr(*str, '\n') ?
		ft_strsub(*str, 0, bsn - *str) : ft_strdup(*str);
	if (!line)
		return (-1);
	if (bsn)
		ft_strcpy(*str, bsn + 1);
	return (1);
}

int		ft_read(char **line, int fd, char **str)
{
	char	*buf;
	size_t	ret;
	int		ret2;

	if (!(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	ret = 1;
	while (!ft_strchr_sec(*str, '\n') &&
		(ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(*str = ft_strjoinfree(*str, buf, 1)))
			return (-1);
	}
	ft_strdel(&buf);
	if ((!*str || (ft_strlen(*str) < 1)) && ret == 0)
		return (0);
	if ((ret2 = ft_check(str, line)) < 0)
		return (ret2);
	if (!ret)
		ft_strdel(str);
	return (ret || **line);
}

int		get_next_line(int fd, char **line)
{
	static t_list	*lst = NULL;
	t_list			*tmp;

	if (BUFF_SIZE < 1 || (read(fd, NULL, 0) == -1) || !line || fd < 0)
		return (-1);
	if ((!lst && !(lst = ft_newlst(NULL, fd))) || fd < 0)
		return (-1);
	tmp = lst;
	while (tmp->next && tmp->content_size != (size_t)fd)
		tmp = tmp->next;
	if (tmp->content_size != (size_t)fd)
	{
		if (!(tmp->next = ft_newlst(NULL, fd)))
			return (-1);
		tmp = tmp->next;
	}
	return (ft_read(line, fd, (char **)&tmp->content));
}
