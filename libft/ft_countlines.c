/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countlines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 08:45:05 by jfarinha          #+#    #+#             */
/*   Updated: 2018/11/06 11:44:15 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h>

int		ft_countlines(char *file)
{
	int		i;
	int		fd;
	char	line[BUFF_SIZE];

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	i = 0;
	while (read(fd, line, BUFF_SIZE))
		i += ft_strfindoc(line, '\n');
	close(fd);
	return (i);
}
