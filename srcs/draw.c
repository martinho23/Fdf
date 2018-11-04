/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 18:09:07 by jfarinha          #+#    #+#             */
/*   Updated: 2018/11/04 20:21:22 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <fdf.h>

void	line(t_sys sys, t_point a, t_point b, int color)
{
	t_point	drawp;

	drawp.x = (fabs(b.x - a.x) > fabs(b.y - a.y)) ? (b.x - a.x) / \
	fabs(b.x - a.x) : (b.x - a.x) / fabs(b.y - a.y);
	drawp.y = (fabs(b.x - a.x) > fabs(b.y - a.y)) ? (b.y - a.y) / \
	fabs(b.x - a.x) : (b.y - a.y) / fabs(b.y - a.y);

	while ((int)a.x != (int)b.x && (int)a.y != (int)b.y)
	{
		if (on_screen(a))
			mlx_pixel_put(sys.mlx, sys.win, ceil(a.x), ceil(a.y), color);
		a.x += drawp.x;
		a.y += drawp.y;
	}
}
