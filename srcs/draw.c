/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 18:09:07 by jfarinha          #+#    #+#             */
/*   Updated: 2019/09/26 20:30:11 by jfarinha         ###   ########.fr       */
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
	int			i;

	a.x = round(a.x);
	a.y = round(a.y);
	b.x = round(b.x);
	b.y = round(b.y);
	coef.x = (fabs(b.x - a.x) > fabs(b.y - a.y)) ? (b.x - a.x) / \
	fabs(b.x - a.x) : (b.x - a.x) / fabs(b.y - a.y);
	coef.y = (fabs(b.x - a.x) > fabs(b.y - a.y)) ? (b.y - a.y) / \
	fabs(b.x - a.x) : (b.y - a.y) / fabs(b.y - a.y);
	i = (fabs(b.x - a.x) > fabs(b.y - a.y)) ? (int)fabs(b.x - a.x) : \
		(int)fabs(b.y - a.y);

	while (i && on_screen(a))
	{
			mlx_pixel_put(sys->mlx, sys->win, round(a.x), round(a.y), color);
//			printf("Ax: %f, Ay: %f\n", a.x, a.y);
//			printf("Bx: %f, By: %f\n", b.x, b.y);
		a.x += coef.x;
		a.y += coef.y;
		i--;
    }
}

t_matrix4f	loadProjection(double a, double f, double q)
{
	t_matrix4f	projection = {  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0  };

    float       d = 0.5f * WINW * tan(45);
    (void)a;
    (void)f;
	(void)q;
/*	projection[0][0] = d;
	projection[1][1] = d * (WINW / WINH);
	projection[2][2] = 1;
	projection[2][3] = 1; */
    printf("Projection D:%f, A:%f, FOV:%f\n", d, (WINW / WINH), f);

	return (projection);
}

static void	draw_hor(t_sys *env)
{
	t_size		i;
	t_size		j;
	t_vector3f	a;
	t_vector3f	b;
	p_matrix4f	draw;
	p_matrix4f	translate;

	draw = newMatrix4();
	translate = newMatrix4();
	initTranslate(env, translate);
	matrix4Mul(translate, &env->projection, draw);
    float ar = WINW / WINH;
    float d = 0.5f * WINW * tan(45);
	j = 0;
    a.x = 0;
    a.y = 0;
    a.z = 0;
    b.x = 0;
    b.y = 0;
    b.z = 0;

	while (j < env->size_y)
	{
		i = 0;
		while (i < env->size_x - 1)
		{
			//a = vec4Mul(draw, env->map[j][i]);
			//b = vec4Mul(draw, env->map[j][i + 1]);
/*			a.x *= WINW;
			a.y *= WINH;
			b.x *= WINW;
			b.y *= WINH;
			a.x = (a.x + 1.0f) * 0.5f * WINW;
			a.y = (a.y + 1.0f) * 0.5f * WINH;
			b.x = (b.x + 1.0f) * 0.5f * WINW;
			b.y = (b.y + 1.0f) * 0.5f * WINH;*/
            a.x = (env->map[j][i].x * d) / env->map[j][i].z;
            a.x = (env->map[j][i].x * d) / env->map[j][i].z;
            b.y = (env->map[j][i +1].y * d * ar) / env->map[j][i+1].z;
            b.y = (env->map[j][i +1].y * d * ar) / env->map[j][i+1].z;

            printf("Ax: %f, Ay: %f, Az: %f\n", a.x, a.y, a.z);
			printf("Bx: %f, By: %f, Bz: %f\n", b.x, b.y, b.z);
           
			if (on_screen(a) || on_screen(b))
				line(env, a, b, mkcolor(0, 255, 0));
			i++;
		}
		j++;
	}
	delMatrix4(&draw);
}

int     draw(t_sys *env)
{
	t_size				i;
	t_size				j;
	t_vector3f			a;
	t_vector3f			b;
	p_matrix4f			draw;
	p_matrix4f			translate;

	draw = newMatrix4();
	translate = newMatrix4();
	initTranslate(env, translate);
	matrix4Mul(translate, &env->projection, draw);
	mlx_clear_window(env->mlx, env->win);
	j = 0;
	while (j < env->size_x && draw)
	{
		i = 0;
		while (i < env->size_y - 1)
		{
			a = vec4Mul(draw, env->map[i][j]);
			b = vec4Mul(draw, env->map[i + 1][j]);
/*			a.x *= WINW;
			a.y *= WINH;
			b.x *= WINW;
			b.y *= WINH;*/
			a.x = (a.x + 1.0f) * 0.5f * WINW;
			a.y = (a.y + 1.0f) * 0.5f * WINH;
			b.x = (b.x + 1.0f) * 0.5f * WINW;
			b.y = (b.y + 1.0f) * 0.5f * WINH;
/*			printf("Ax: %f, Ay: %f, Az: %f\n", a.x, a.y, a.z);
			printf("Bx: %f, By: %f, Bz: %f\n", b.x, b.y, b.z);*/
			if (on_screen(a) || on_screen(b))
				line(env, a,  b, mkcolor(0, 255, 0));
			i++;
		}
		j++;
		draw_hor(env);
	}
	delMatrix4(draw);
    return (0);
}
