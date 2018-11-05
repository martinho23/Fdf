/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 11:52:09 by jfarinha          #+#    #+#             */
/*   Updated: 2018/11/05 17:40:57 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <libft.h>

static t_vector3f	*loadLine(t_sys *env, char *line)
{
	t_vector3f	*points;
	t_size		i;
	char		**vals;

	vals = ft_strsplit(line, ' ');
	i = 0;
	if (!env->size_x)
		while (vals[env->size_x])
			env->size_x++;
	printf("Size X: %d\n", env->size_x);
	ft_thrower(((points = (t_vector3f *)malloc(sizeof(*points) * env->size_x))\
== NULL), "Malloc error: Not enought memory!");
	while (i < env->size_x)
	{
		points[i].x = (double)(i * STDW);
		points[i].y = (double)(env->size_y * STDH);
		points[i].z = (double)ft_atoi(vals[i]);
		i++;
		printf("Map vals: X[%lf] Y[%lf] Z[%lf]\n", (double)(i * STDW), (double)(env->size_y * STDH), (double)0);
		printf("Point vals: X[%lf] Y[%lf] Z[%lf]\n", points[i].x, points[i].y, points[i].z);
		free(vals[i]);
	}
	free(vals[i]);
	free(vals);
	return (points);
}

void	load(char *map, t_sys *env)
{
	t_list	*lines;
	t_list	*tmp;
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	ft_thrower((fd < 0), "Map error: Couldn't open the specified file!");
	lines = NULL;
	tmp = NULL;
	env->size_x = 0;
	env->size_y = 0;
	while (get_next_line(fd, &line))
	{
		tmp = ft_lstnew(loadLine(env, line), sizeof(t_vector3f*));
		ft_lstadd(&lines, tmp);
		env->size_y++;
	}
	close(fd);
}
