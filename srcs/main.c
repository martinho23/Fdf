/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 17:24:39 by jfarinha          #+#    #+#             */
/*   Updated: 2018/11/06 17:03:21 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fdf.h>
#include <libft.h>

int		main(int ac, char **av)
{
	t_sys	sys;

	ft_thrower(ac != 2, "Usage: You must specify a map file to load!");
	sys.mlx = mlx_init();
	sys.win = mlx_new_window(sys.mlx, WINW, WINH, "FDF");
	load(av[1], &sys);
	ft_thrower(sys.size_x <= 0 || sys.size_y <= 0, "Map error: wrong format!");
	mlx_key_hook(sys.win, keyhook, &sys);
	sys.cam.x = WINW / 2;
	sys.cam.y = WINH / 2;
	sys.cam.z = 1;
	draw(&sys);
	mlx_loop(sys.mlx);
	return (0);
}
