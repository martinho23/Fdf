/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 17:24:39 by jfarinha          #+#    #+#             */
/*   Updated: 2019/09/22 13:20:47 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fdf.h>
#include <libft.h>
#include <stdio.h>
#include <math.h>

int		main(int ac, char **av)
{
	t_sys		env;

	ft_thrower(ac != 2, "Usage: You must specify a map file to load!");
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WINW, WINH, "FDF");
	load(av[1], &env);
	ft_thrower(env.size_x <= 0 || env.size_y <= 0, "Map error: wrong format!");
	env.a = (WINH / WINW);
	env.f = 1 / tan(FOV / 2);
	env.q = ZFAR / (ZFAR - ZNEAR);
	printf("a: %f, f: %f q: %f\n", env.a, env.f, env.q);
	env.projection = loadProjection(env.a, env.f, env.q);
	env.translate.x = 0;
	env.translate.y = 0;
	env.translate.z = 0;
	env.scale.x = 1;
	env.scale.y = 1;
	env.scale.z = 1;
	draw(&env);
	printf("print done!\n");
	mlx_key_hook(env.win, keyhook, &env);
	mlx_loop(env.mlx);
	return (0);
}
