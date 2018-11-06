/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 18:09:07 by jfarinha          #+#    #+#             */
/*   Updated: 2018/11/06 21:16:15 by jfarinha         ###   ########.fr       */
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

		printf("RND A: |%.18f, %.18f| B: |%.18f, %.18f|\n", round(a.x), round(a.y), round(b.x), round(b.y));
		printf("NRD A: |%.18f, %.18f| B: |%.18f, %.18f| COEF: |%.18f, %.18f|\n", a.x, a.y, b.x, b.y, coef.x, coef.y);
	while (round(a.x) != round(b.x) || round(a.y) != round(b.y))
	{
		if (on_screen(a))
			mlx_pixel_put(sys.mlx, sys.win, round(a.x), round(a.y), color);
		if (ceil(a.x) > ceil(b.x) -1 && ceil(a.x) < ceil(b.x +1))
		{
			//printf("RND A: |%.18f, %.18f| B: |%.18f, %.18f|\n", round(a.x), round(a.y), round(b.x), round(b.y));
			//printf("NRD A: |%.18f, %.18f| B: |%.18f, %.18f| COEF: |%.18f, %.18f|\n", a.x, a.y, b.x, b.y, coef.x, coef.y);
		}
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
			if (on_screen(a) || on_screen(b))
				line(*env, a, b, mkcolor(0, 255, 0));
			i++;
		}
		j++;
	}
	draw_hor(env);
}
