/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 11:52:09 by jfarinha          #+#    #+#             */
/*   Updated: 2019/09/23 19:01:59 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <libft.h>

static t_vector3f	*loadLine(t_sys *env, char *line, t_size y)
{
	t_vector3f	*points;
	t_size		i;
	char		**vals;

	vals = ft_strsplit(line, ' ');
	i = 0;
	if (!env->size_x)
		while (vals[env->size_x])
			env->size_x++;
	ft_thrower(((points = (t_vector3f *)malloc(sizeof(*points) * env->size_x))\
== NULL), "Malloc error: Not enought memory!");
	while (i < env->size_x)
	{
		points[i].x = (double)i;
		points[i].y = (double)y;
		points[i].z = ft_atoi(vals[i]);
		if (env->size_z < points[i].z)
			env->size_z = points[i].z;
		free(vals[i]);
		i++;
	}
	free(vals[i]);
	free(vals);
	return (points);
}
static void			normalise(t_sys *env)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < env->size_y)
	{
		j = 0;
		while (j < env->size_x)
		{
			env->map[i][j].x /= env->size_x;
			env->map[i][j].y /= env->size_y;
			env->map[i][j].z /= env->size_z;
			j++;
		}
		i++;
	}
}

void				load(char *map, t_sys *env)
{
	int		fd;
	char	*line;
	t_size	i;

	fd = open(map, O_RDONLY);
	ft_thrower((fd < 0), "Map error: Couldn't open the specified file!");
	env->size_x = 0;
	env->size_z = 0;
	env->size_y = ft_countlines(map);
	ft_thrower((env->map = (t_vector3f **)malloc(sizeof(*(env->map)) * \
env->size_y)) == NULL, "Malloc error: Not enought memory!");
	i = 0;
	while (get_next_line(fd, &line))
	{
		env->map[i] = loadLine(env, line, i);
		i++;
	}
	normalise(env);
	printf("X: %i\n", env->size_x);
	printf("Y: %i\n", env->size_y);
	printf("Z: %i\n", env->size_z);
	close(fd);
}

