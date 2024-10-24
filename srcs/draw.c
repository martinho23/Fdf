/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 18:09:07 by jfarinha          #+#    #+#             */
/*   Updated: 2024/10/24 22:54:40 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <fdf.h>
#include <libft.h>

t_matrix4f	loadProjection(void)
{
    /*
    const float       d = 0.5f * WINW * tan(45);
	const t_matrix4f  m =  {{{{ d, 0,   0,  0 }, \
                            {   0, d,   0,  0 }, \
                            {   0, 0,   1,  1 }, \
                            {   0, 0,   0,  0 }}}};
    */

    const float a = 0.5f * WINW - 0.5f;
    const float b = 0.5f * WINH - 0.5f;
	const t_matrix4f  m =  {{{{ a, 0,   0,  0 }, \
                            {   0, 1 * b,   0,  0 }, \
                            {   a, b,   1,   0}, \
                            {   0, 0,   0,  1 }}}};
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

	draw = newMatrix4f();
	translate = newMatrix4f();
	initTranslate(env, translate);
	matrix4Mul(translate, &env->projection, draw);

	j = 0;
    while (j < env->size_y)
	{
		i = 0;
		while (i < env->size_x - 1)
		{
		    a = vec4Mul(*draw, &env->map[j][i]);
		    b = vec4Mul(*draw, &env->map[j][i + 1]);

            a.x /= a.z;
            a.y /= a.z;
            b.x /= b.z;
            b.y /= b.z;

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
	ptr_matrix4f		draw;
	ptr_matrix4f		translate;

	draw = newMatrix4f();
	translate = newMatrix4f();
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

            a.x /= a.z;
            a.y /= a.z;
            b.x /= b.z;
            b.y /= b.z;

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
