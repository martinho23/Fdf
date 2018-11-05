/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 19:57:38 by jfarinha          #+#    #+#             */
/*   Updated: 2018/03/28 10:28:21 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32

typedef struct	s_fd_handler
{
	int					fd;
	int					line_nb;
	char				*buf;
	struct s_fd_handler	*nextfd;
}				t_fd_handler;
int				get_next_line(int fd, char **line);
int				readf(t_fd_handler *handler);
int				process(t_fd_handler **h, char **line);
void			delfd(t_fd_handler **handler);
t_fd_handler	*newfd(int fd);

#endif
