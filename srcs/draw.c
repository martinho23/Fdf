/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 18:09:07 by jfarinha          #+#    #+#             */
/*   Updated: 2024/10/27 22:24:50 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fdf_matrix.h>
#include <fdf.h>
#include <libft.h>

t_matrix4f	loadProjection(void)
{
    const float a = 0.5f * WINW - 0.5f;
    const float b = 0.5f * WINH - 0.5f;
	const t_matrix4f  m =  {{{{ a, 0,       0,  0}, \
                            {   0, -b,  0,  0}, \
                            {   a, b,       1,  1}, \
                            {   0, 0,       0,  0}}}};
	return (m);
}

int     draw(t_sys *env)
{
	t_size				i;
	t_size				j;
	t_vector4f			a;
	t_vector4f			b;
    t_vector4f          c;
    t_vector4f          d;
    t_matrix4f          draw = MATRIX_ZERO;
    t_matrix4f          translate = MATRIX_ZERO;
    t_matrix4f          rotx = MATRIX_ROT_X(env->angle);
    t_matrix4f          tmp = MATRIX_ZERO;

    (void)tmp;
    env->angle = DEGREETORAD(155.f);
	initTranslate(env, &translate);
    matrix4Mul(&rotx, &translate, &tmp);
	matrix4Mul(&tmp, &env->projection, &draw);
	clearScreenSurface(env, 0x18181818);

    j = 0;
    while (j < env->size_x - 1)
	{
		i = 0;
		while (i < env->size_y - 1)
		{
			a = vec4MulHomogenous(draw, &env->map[i][j]);
			b = vec4MulHomogenous(draw, &env->map[i][j + 1]);
            c = vec4MulHomogenous(draw, &env->map[i + 1][j]);
            d = vec4MulHomogenous(draw, &env->map[i + 1][j + 1]);

            brazehanLine(env, MAKE_VECTOR2I(a.x, a.y),  MAKE_VECTOR2I(b.x, b.y), mkcolor(0, 255, 0));
			brazehanLine(env, MAKE_VECTOR2I(b.x, b.y),  MAKE_VECTOR2I(d.x, d.y), mkcolor(0, 255, 0));
			brazehanLine(env, MAKE_VECTOR2I(c.x, c.y),  MAKE_VECTOR2I(d.x, d.y), mkcolor(0, 255, 0));
    		brazehanLine(env, MAKE_VECTOR2I(a.x, a.y),  MAKE_VECTOR2I(c.x, c.y), mkcolor(0, 255, 0));
            i++;
		}
		j++;
	}
	//draw_hor(env);
    drawBuffer(env);
    return (0);
}
