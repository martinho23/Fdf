/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 19:57:25 by jfarinha          #+#    #+#             */
/*   Updated: 2018/07/18 19:52:18 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"
#include "libft.h"

t_fd_handler	*newfd(int fd)
{
	t_fd_handler *h;

	h = NULL;
	if ((h = (t_fd_handler*)malloc(sizeof(*h))))
	{
		h->fd = fd;
		h->buf = NULL;
		h->line_nb = 0;
		h->nextfd = NULL;
	}
	return (h);
}

int				readfd(t_fd_handler *h)
{
	int		rdc;
	char	buff[BUFF_SIZE + 1];

	if (h->buf == NULL)
		if (!(h->buf = ft_strnew(0)))
			return (-1);
	while (h->line_nb == 0 && (rdc = read(h->fd, buff, BUFF_SIZE)) > 0)
	{
		buff[rdc] = '\0';
		h->buf = ft_strfreejoin(h->buf, buff);
		h->line_nb += ft_strfindoc(buff, '\n');
	}
	if (rdc < 0)
		return (-1);
	return (0);
}

void			delfd(t_fd_handler **h)
{
	t_fd_handler	*old;

	if (h != NULL)
	{
		old = *h;
		*h = (*h)->nextfd;
		old->fd = -1;
		ft_strdel(&old->buf);
		ft_memdel((void**)&old);
	}
}

int				process(t_fd_handler **h, char **line)
{
	char	*p_endl;
	char	*old;

	p_endl = ft_strchr((*h)->buf, '\n');
	if ((*h)->line_nb)
	{
		old = (*h)->buf;
		(*h)->buf = ft_strdup(p_endl + 1);
		(*h)->line_nb -= 1;
		*line = ft_strsub(old, 0, p_endl - old);
		ft_strdel(&old);
		return (1);
	}
	else
	{
		*line = ft_strdup((*h)->buf);
		delfd(h);
		return (0);
	}
}

int				get_next_line(int fd, char **line)
{
	static t_fd_handler	*f = NULL;
	t_fd_handler		**tmp;

	if (fd < 0 || !line)
		return (-1);
	if (!f && !(f = newfd(fd)))
		return (-1);
	tmp = &f;
	while (*tmp && (*tmp)->fd != fd)
		tmp = &(*tmp)->nextfd;
	if (*tmp == NULL && !(*tmp = newfd(fd)))
		return (-1);
	if (readfd(*tmp) == -1)
		return (-1);
	if (process(tmp, line) == 0 && *line && !*line[0])
		return (0);
	return (1);
}
