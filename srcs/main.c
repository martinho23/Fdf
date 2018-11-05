/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 17:24:39 by jfarinha          #+#    #+#             */
/*   Updated: 2018/11/05 10:18:41 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fdf.h>

int		main()
{
	t_sys	sys;
	t_point	a;
	t_point	b;

	sys.mlx = mlx_init();
	sys.win = mlx_new_window(sys.mlx, WINW, WINH, "FDF");
	a.x = 0; a.y = 0;
	b.x = 600; b.y = 400;
	line(sys, a, b, mkcolor(255, 0, 0));
	a.x = 0; a.y = 400;
	b.x = 600; b.y = 0;
	line(sys, a, b, mkcolor(0, 255, 0));
	mlx_loop(sys.mlx);
	return (0);
}
