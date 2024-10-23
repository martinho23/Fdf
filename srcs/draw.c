/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 18:09:07 by jfarinha          #+#    #+#             */
/*   Updated: 2024/10/22 19:10:10 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include <fdf.h>
#include <libft.h>

static  t_vector2f clampPointToScreen(t_sys *sys, t_vector2f point)
{
    t_screenSurface *screen = sys->screenSurface;

    //printf("Before clamp Point X:%d, Y:%d\n", (int)(point.x), (int)(point.y));
    if ((int)point.x < 0)
        point.x =  0;
    if ((int)point.x > screen->size.x)
        point.x = (float)screen->size.x;
    if ((int)point.y < 0)
        point.y = 0;
    if ((int)point.y > screen->size.y)
        point.y = (float)screen->size.y;
    //printf("After clamp Point X:%d, Y:%d\n", (int)(point.x), (int)(point.y));
    
    return (point);
}

static inline double mind(double a, double b)
{
    return ((a < b) ? a : b);
}

static inline double maxd(double a, double b)
{
    return ((a > b) ? a : b);
}

static inline int mini(int  a, int b)
{
    return ((a < b) ? a : b);
}

static inline int maxi(int  a, int b)
{
    return ((a > b) ? a : b);
}

static inline void putPixelToScreenSurface(t_screenSurface *screen, t_vector2i point, unsigned int color)
{
    char *dest;

    dest = (screen->addr + (point.y * screen->lineSize) + ((point.x * screen->pixelSize) / 8));
    *(unsigned int *)dest = color;
}

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

void		line(t_sys *sys, t_vector2f a, t_vector2f b, int color)
{
    t_vector2f delta;
    t_vector2f linePoint;
    int         step;

    a = clampPointToScreen(sys, a);
    b = clampPointToScreen(sys, b);
    
    delta.x = fabs(b.x - a.x);
    delta.y = fabs(b.y - a.y);

    step = (delta.x > delta.y) ? delta.x : delta.y;

    delta.x /= step;
    delta.y /= step;

    linePoint.x = mind(a.x, b.x);
    linePoint.y = mind(a.y, b.y);

    
    while (step)
    {
        t_vector2i point = {{{(int)linePoint.x, (int)linePoint.y}}};
       
        putPixelToScreenSurface(sys->screenSurface, point, color);
     
        linePoint.x += delta.x;
        linePoint.y += delta.y;

        step --;
    }       

}

void        brazehanLine(t_sys *env, t_vector2i a, t_vector2i b, int color)
{
    t_vector2i  delta;
    t_vector2i  point;
    int         error;

    delta = (t_vector2i){{{b.x - a.x, b.y - a.y}}};
    if (delta.x > delta.y)
    {
        point = (t_vector2i){{{a.x, a.y}}};
        error = 2 * delta.y - delta.x;

        while (point.x < b.x)
        {
            putPixelToScreenSurface(env->screenSurface, point, color);

            if (error >= 0)
            {
                point.y += 1;
                error += 2 * delta.y - 2 * delta.x;
            }
            else
            {
                error += 2 * delta.y;
            }
            point.x ++;
        }
    }
    else
    {
        point = (t_vector2i){{{a.x, a.y}}};
        error = 2 * delta.x - delta.y;

        while (point.y < b.y)
        {
            putPixelToScreenSurface(env->screenSurface, point, color);

            if (error >= 0)
            {
                point.x += 1;
                error += 2 * delta.x - 2 * delta.y;
            }
            else
            {
                error += 2 * delta.x;
            }
            point.y ++;
        }

    }

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
		    a = vec4Mul(*draw, &env->map[j][i]);
		    b = vec4Mul(*draw, &env->map[j][i + 1]);

            a.x /= a.w;
            a.y /= a.w;
            b.x /= b.w;
            b.y /= b.w;

//            printf("Ax: %f, Ay: %f, Az: %f\n", a.x, a.y, a.z);
//			printf("Bx: %f, By: %f, Bz: %f\n", b.x, b.y, b.z);
           
			if (on_screen(a) || on_screen(b))
				brazehanLine(env, (t_vector2i){{{a.x, a.y}}}, (t_vector2i){{{b.x, b.y}}}, mkcolor(0, 255, 0));
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
/*
 *			printf("Ax: %f, Ay: %f, Az: %f\n", a.x, a.y, a.z);
 *			printf("Bx: %f, By: %f, Bz: %f\n", b.x, b.y, b.z);
*/


			if (on_screen(a) || on_screen(b))
				brazehanLine(env, (t_vector2i){{{a.x, a.y}}},  (t_vector2i){{{b.x, b.y}}}, mkcolor(0, 255, 0));
			i++;
		}
		j++;
	}
	draw_hor(env);
	delMatrix4(draw);
    drawBuffer(env);
    return (0);
}
