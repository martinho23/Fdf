/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 18:09:07 by jfarinha          #+#    #+#             */
/*   Updated: 2019/09/20 18:53:32 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include <fdf.h>
#include <libft.h>

void		line(t_sys *sys, t_vector3f a, t_vector3f b, int color)
{
	t_vector3f	coef;


	a.x = round(a.x);
	a.y = round(a.y);
	b.x = round(b.x);
	b.y = round(b.y);
	coef.x = (fabs(b.x - a.x) > fabs(b.y - a.y)) ? (b.x - a.x) / \
	fabs(b.x - a.x) : (b.x - a.x) / fabs(b.y - a.y);
	coef.y = (fabs(b.x - a.x) > fabs(b.y - a.y)) ? (b.y - a.y) / \
	fabs(b.x - a.x) : (b.y - a.y) / fabs(b.y - a.y);

	while (round(a.x) != round(b.x) || round(a.y) != round(b.y) /*&& on_screen(a)*/)
	{
//		printf("Ax: %f, Ay: %f\n", a.x, a.y);
//		printf("Bx: %f, By: %f\n", b.x, b.y);
		if (on_screen(a) && (a.x == round(a.x) || a.y == round(a.y)))
			mlx_pixel_put(sys->mlx, sys->win, round(a.x), round(a.y), color);
		a.x += coef.x;
		a.y += coef.y;
	}
}

t_matrix4f	loadProjection(double a, double f, double q)
{
	t_matrix4f	projection;

	projection = newMatrix4();
	if (!projection || !*projection)
		return (NULL);
	projection[0][0] = a * f;
	projection[1][1] = f;
	projection[2][2] = q;
	projection[2][3] = 1;
	projection[3][2] = ZNEAR * q * -1;
	return (projection);
}

static void	draw_hor(t_sys *env)
{
	t_size		i;
	t_size		j;
	t_vector3f	a;
	t_vector3f	b;
	t_matrix4f	draw;

	draw = newMatrix4();
	matrix4Mul(translate(env), env->projection, &draw);
	j = 0;
	while (j < env->size_y)
	{
		i = 0;
		while (i < env->size_x - 1)
		{
			a = vec4Mul(draw, env->map[j][i]);
			b = vec4Mul(draw, env->map[j][i + 1]);
			//printf("Ax: %f, Ay: %f\n", a.x, a.y);
			//printf("Bx: %f, By: %f\n", b.x, b.y);
			if (on_screen(a) || on_screen(b))
				line(env, a, b, mkcolor(0, 255, 0));
			i++;
		}
		j++;
	}
	delMatrix4(&draw);
}

void		draw(t_sys *env)
{
	t_size				i;
	t_size				j;
	t_vector3f			a;
	t_vector3f			b;
	t_matrix4f			draw;

	draw = newMatrix4();
	matrix4Mul(translate(env), env->projection, &draw);
	mlx_clear_window(env->mlx, env->win);
	j = 0;
	while (j < env->size_x && *draw && draw)
	{
		i = 0;
		while (i < env->size_y - 1)
		{
			a = vec4Mul(draw, env->map[i][j]);
			b = vec4Mul(draw, env->map[i + 1][j]);
			//printf("Ax: %f, Ay: %f\n", a.x, a.y);
			//printf("Bx: %f, By: %f\n", b.x, b.y);
			if (on_screen(a) || on_screen(b))
				line(env, a, b, mkcolor(0, 255, 0));
			i++;
		}
		j++;
		draw_hor(env);
	}
	delMatrix4(&draw);
}
