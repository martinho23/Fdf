/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 18:09:07 by jfarinha          #+#    #+#             */
/*   Updated: 2024/10/23 20:57:49 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include <fdf.h>
#include <libft.h>

t_matrix4f	loadProjection(double a, double f, double q)
{
    const float       d = 0.5f * WINW * tan(45);
	const t_matrix4f  m =  {{{{ d, 0,   0,  0 }, \
                            {   0, d,   0,  0 }, \
                            {   0, 0,   1,  1 }, \
                            {   0, 0,   0,  0 }}}};
    (void)a;
    (void)f;
	(void)q;
/*	projection[0][0] = d;
	projection[1][1] = d * (WINW / WINH);
	projection[2][2] = 1;
	projection[2][3] = 1; */
    printf("Projection D:%f, A:%f, FOV:%f\n", d, (WINW / WINH), f);

	return (m);
}

static void	draw_hor(t_sys *env)
{
	t_size		i;
	t_size		j;
	t_vector4f	a;
	t_vector4f	b;
	ptr_matrix4f	draw;
	ptr_matrix4f	translate;

	draw = newMatrix4();
	translate = newMatrix4();
	initTranslate(env, translate);
	matrix4Mul(translate, &env->projection, draw);

	j = 0;
    a = MAKE_VECTOR4F(0, 0, 0, 0);
    b = MAKE_VECTOR4F(0, 0, 0, 0);
   
    while (j < env->size_y)
	{
		i = 0;
		while (i < env->size_x - 1)
		{
		    a = vec4Mul(*draw, &env->map[j][i]);
		    b = vec4Mul(*draw, &env->map[j][i + 1]);

            a.x /= a.w;
            a.y /= a.w;
            b.x /= b.w;
            b.y /= b.w;

			if (on_screen(a) || on_screen(b))
				brazehanLine(env, MAKE_VECTOR2I(a.x, a.y), MAKE_VECTOR2I(b.x, b.y), mkcolor(0, 255, 0));
			i++;
		}
		j++;
	}
	delMatrix4(draw);
}

int     draw(t_sys *env)
{
	t_size				i;
	t_size				j;
	t_vector4f			a;
	t_vector4f			b;
	ptr_matrix4f			draw;
	ptr_matrix4f			translate;

	draw = newMatrix4();
	translate = newMatrix4();
	initTranslate(env, translate);
	matrix4Mul(translate, &env->projection, draw);
	clearScreenSurface(env, 0x18181818);
	j = 0;
	while (j < env->size_x && draw)
	{
		i = 0;
		while (i < env->size_y - 1)
		{
			a = vec4Mul(*draw, &env->map[i][j]);
            b = vec4Mul(*draw, &env->map[i + 1][j]);

            a.x /= a.w;
            a.y /= a.w;
            b.x /= b.w;
            b.y /= b.w;

    		if (on_screen(a) || on_screen(b))
				brazehanLine(env, MAKE_VECTOR2I(a.x, a.y),  MAKE_VECTOR2I(b.x, b.y), mkcolor(0, 255, 0));
			i++;
		}
		j++;
	}
	draw_hor(env);
	delMatrix4(draw);
    drawBuffer(env);
    return (0);
}
