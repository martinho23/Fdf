/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countlines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 08:45:05 by jfarinha          #+#    #+#             */
/*   Updated: 2018/11/06 08:55:53 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

int		ft_countlines(char *file)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	i = 0;
	while (get_next_line(fd, &line))
	{
		free(line);
		i++;
	}
	close(fd);
	return (i);
}
