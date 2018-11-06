/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 18:09:07 by jfarinha          #+#    #+#             */
/*   Updated: 2018/11/06 17:22:38 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include <fdf.h>

void		line(t_sys sys, t_point a, t_point b, int color)
{
	t_point	coef;

	coef.x = (fabs(b.x - a.x) > fabs(b.y - a.y)) ? (b.x - a.x) / \
	fabs(b.x - a.x) : (b.x - a.x) / fabs(b.y - a.y);
	coef.y = (fabs(b.x - a.x) > fabs(b.y - a.y)) ? (b.y - a.y) / \
	fabs(b.x - a.x) : (b.y - a.y) / fabs(b.y - a.y);

	while ((int)a.x != (int)b.x || (int)a.y != (int)b.y)
	{
		if (on_screen(a))
			mlx_pixel_put(sys.mlx, sys.win, ceil(a.x), ceil(a.y), color);
		a.x += coef.x;
		a.y += coef.y;
	}
}

static void	draw_hor(t_sys *env)
{
	t_size	i;
	t_size	j;
	t_point	a;
	t_point	b;

	j = 0;
	while (j < env->size_y)
	{
		i = 0;
		while (i < env->size_x - 1)
		{
			a = vectop(env->map[j][i], env->cam);
			b = vectop(env->map[j][i + 1], env->cam);
			if (on_screen(a) || on_screen(b))
				line(*env, a, b, mkcolor(0, 255, 0));
			i++;
		}
		j++;
	}
}

void		draw(t_sys *env)
{
	t_size	i;
	t_size	j;
	t_point	a;
	t_point	b;

	j = 0;
	while (j < env->size_x)
	{
		i = 0;
		while (i < env->size_y - 1)
		{
			a = vectop(env->map[i][j], env->cam);
			b = vectop(env->map[i + 1][j], env->cam);
			if (!on_screen(a) && on_screen(b) || !on_screen(b) && on_screen(a))
				
			line(*env, a, b, mkcolor(0, 255, 0));
			i++;
		}
		j++;
	}
	draw_hor(env);
}
