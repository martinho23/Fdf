/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 11:52:09 by jfarinha          #+#    #+#             */
/*   Updated: 2018/11/06 17:17:31 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
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
		points[i].x = (double)(i * STDW);
		points[i].y = (double)(y * STDH);
		points[i].z = (ft_atoi(vals[i])) ? ft_atoi(vals[i]) : 1;
		free(vals[i]);
		i++;
	}
	free(vals[i]);
	free(vals);
	return (points);
}

void				load(char *map, t_sys *env)
{
	int		fd;
	char	*line;
	t_size	i;

	fd = open(map, O_RDONLY);
	ft_thrower((fd < 0), "Map error: Couldn't open the specified file!");
	env->size_x = 0;
	env->size_y = ft_countlines(map);
	ft_thrower((env->map = (t_vector3f **)malloc(sizeof(*(env->map)) * \
env->size_y)) == NULL, "Malloc error: Not enought memory!");
	i = 0;
	while (get_next_line(fd, &line))
	{
		env->map[i] = loadLine(env, line, i);
		i++;
	}
	close(fd);
}
