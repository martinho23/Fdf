/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 18:09:07 by jfarinha          #+#    #+#             */
/*   Updated: 2024/10/27 00:12:13 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <fdf.h>
#include <libft.h>

#define MAKEROTY(angle)  {{{{cos(angle),    0,  sin(angle), 0},\
                            {0,             1,  0,          0},\
                            {-1*sin(angle), 0,  cos(angle), 0},\
                            {0,             0,  0,          1}}}}

#define MAKEROTX(angle)  {{{{1, 0,          0,              0},\
                            {0, cos(angle), -1*sin(angle),  0},\
                            {0, sin(angle), cos(angle),     0},\
                            {0, 0,          0,              1}}}}


#define MAKEROT0(angle)  {{{{1, 0, 0, 0},\
                            {0, 1, 0, 0},\
                            {0, 0, 1, 0},\
                            {0, 0, 0, 1}}}}


#define MAKEZEROMATRIX  {{{{0, 0, 0, 0},\
                            {0, 0, 0, 0},\
                            {0, 0, 0, 0},\
                            {0, 0, 0, 0}}}}


   

t_matrix4f	loadProjection(void)
{
    
/*    const float       d = 0.5f * WINW * tan(45);
	const t_matrix4f  m =  {{{{ d, 0,   0,  0 }, \
                            {   0, d,   0,  0 }, \
                            {   0, 0,   1,  1 }, \
                            {   0, 0,   0,  0 }}}}; */
    

    const float a = 0.5f * WINW - 0.5f;
    const float b = 0.5f * WINH - 0.5f;
	const t_matrix4f  m =  {{{{ a, 0,       0,  0}, \
                            {   0, -1 *  b,  0,  0}, \
                            {   a, b,       1,  1}, \
                            {   0, 0,       0,  0}}}};
	return (m);
}

static void	draw_hor(t_sys *env)
{
	t_size		    i;
	t_size		    j;
	t_vector4f	    a;
	t_vector4f	    b;
    t_matrix4f      draw = MAKEZEROMATRIX;
    t_matrix4f      translate = MAKEZEROMATRIX;
    t_matrix4f      roty = MAKEROTX(env->angle);
    t_matrix4f      tmp = MAKEZEROMATRIX;

	initTranslate(env, &translate);
    matrix4Mul(&roty, &translate, &tmp);
	matrix4Mul(&tmp, &env->projection, &draw);

	j = 0;
    while (j < env->size_y)
	{
		i = 0;
		while (i < env->size_x - 1)
		{
		    a = vec4Mul(draw, &env->map[j][i]);
		    b = vec4Mul(draw, &env->map[j][i + 1]);

            a.x /= a.z;
            a.y /= a.z;
            b.x /= b.z;
            b.y /= b.z;

			brazehanLine(env, MAKE_VECTOR2I(a.x, a.y), MAKE_VECTOR2I(b.x, b.y), mkcolor(0, 255, 0));
			i++;
		}
		j++;
	}
}

int     draw(t_sys *env)
{
	t_size				i;
	t_size				j;
	t_vector4f			a;
	t_vector4f			b;
    t_matrix4f          draw = MAKEZEROMATRIX;
    t_matrix4f          translate = MAKEZEROMATRIX;
    t_matrix4f          roty = MAKEROTX(env->angle);
    t_matrix4f          tmp = MAKEZEROMATRIX;

    env->angle += DEGREETORAD(5);
	initTranslate(env, &translate);
    matrix4Mul(&roty, &translate,&tmp);
	matrix4Mul(&tmp, &env->projection, &draw);
	clearScreenSurface(env, 0x18181818);

    j = 0;
	while (j < env->size_x)
	{
		i = 0;
		while (i < env->size_y - 1)
		{
			a = vec4Mul(draw, &env->map[i][j]);
            b = vec4Mul(draw, &env->map[i + 1][j]);

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
    drawBuffer(env);
    return (0);
}
