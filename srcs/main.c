/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 17:24:39 by jfarinha          #+#    #+#             */
/*   Updated: 2018/11/05 16:48:07 by jfarinha         ###   ########.fr       */
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
	mlx_key_hook(sys.win, keyhook, &sys);
	mlx_loop(sys.mlx);
	return (0);
}
