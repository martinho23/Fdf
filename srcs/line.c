/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:56:07 by jfarinha          #+#    #+#             */
/*   Updated: 2024/10/31 01:34:47 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <math.h>
#include <stdlib.h>

void		ddaLine(t_sys *sys, t_vector2f a, t_vector2f b, int color)
{
    t_vector2f delta;
    t_vector2f linePoint;
    int         step;

    a = clampVector2f(a, MAKE_VECTOR2F(0, 0), MAKE_VECTOR2F((float)sys->screenSurface->width -1, (float)sys->screenSurface->height -1));
    b = clampVector2f(b, MAKE_VECTOR2F(0, 0), MAKE_VECTOR2F((float)sys->screenSurface->width -1, (float)sys->screenSurface->height -1));
    
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

inline static void brazehanStraight(t_brazehanData *data)
{
    if (data->delta.y == 0)
    {
        if (data->sign.x > 0)
            while (data->start.x < data->end.x)
            {
                mlx_put_pixel(data->screen, data->start.x, data->start.y, data->color);
                data->start.x ++;
            }
        else
            while (data->start.x > data->end.x)
            {
                 mlx_put_pixel(data->screen, data->start.x, data->start.y, data->color);
                data->start.x --;
            }
    }
    else
    {
        if (data->sign.y > 0)
            while (data->start.y < data->end.y)
            {
                mlx_put_pixel(data->screen, data->start.x, data->start.y, data->color);
                data->start.y ++;
            }
        else
            while (data->start.y > data->end.y)
            {
                mlx_put_pixel(data->screen, data->start.x, data->start.y, data->color);
                data->start.y --;
            }
    }
}

inline static void brazehanHorizontalVertical(t_brazehanData *data)
{
    data->error = 2 * data->delta.y - data->delta.x;
    while (data->start.x < data->end.x || data->start.y < data->end.y)       
    {
        mlx_put_pixel(data->screen, data->start.x, data->start.y, data->color);

        if (data->error >= 0)
        {
            data->start.y += data->sign.y;
            data->error += 2 * data->delta.y - 2 * data->delta.x;
        }
        else
           data->error += 2 * data->delta.y;
        data->start.x += data->sign.x;
    }
    while (data->start.x > data->end.x || data->start.y > data->end.y)       
    {
        mlx_put_pixel(data->screen, data->start.x, data->start.y, data->color);

        if (data->error >= 0)
        {
            data->start.y += data->sign.y;
            data->error += 2 * data->delta.y - 2 * data->delta.x;
        }
        else
           data->error += 2 * data->delta.y;
        data->start.x += data->sign.x;
    }
}



inline static void brazehanVerticalHorizontal(t_brazehanData *data)
{
    data->error = 2 * data->delta.x - data->delta.y;
    while (data->start.y < data->end.y || data->start.x < data->end.x)
    {
        mlx_put_pixel(data->screen, data->start.x, data->start.y, data->color);

        if (data->error >= 0)
        {
            data->start.x += data->sign.x;
            data->error += 2 * data->delta.x - 2 * data->delta.y;
        }
        else
            data->error += 2 * data->delta.x;
        data->start.y += data->sign.y;
    }
    while (data->start.y > data->end.y || data->start.x > data->end.x)
    {
        mlx_put_pixel(data->screen, data->start.x, data->start.y, data->color);

        if (data->error >= 0)
        {
            data->start.x += data->sign.x;
            data->error += 2 * data->delta.x - 2 * data->delta.y;
        }
        else
            data->error += 2 * data->delta.x;
        data->start.y += data->sign.y;
    }
}

void        brazehanLine(t_sys *env, t_vector2i a, t_vector2i b, int color)
{
    t_brazehanData data;
   
    data.screen = env->screenSurface;
    a = clampVector2i(a, MAKE_VECTOR2I(0, 0), MAKE_VECTOR2I(data.screen->width -1, data.screen->height -1));
    b = clampVector2i(b, MAKE_VECTOR2I(0, 0), MAKE_VECTOR2I(data.screen->width -1, data.screen->height -1));

    data.delta = MAKE_VECTOR2I(abs(b.x - a.x), abs(b.y - a.y));
    data.sign = MAKE_VECTOR2I((a.x < b.x ? 1 : -1), (a.y < b.y ? 1 : -1));
    data.start = a;
    data.end = b;
    data.color = color;

    if (data.delta.y == 0 || data.delta.x == 0)
    {
        brazehanStraight(&data);
    }
    else if (data.delta.x > data.delta.y)
    {
        brazehanHorizontalVertical(&data);
    }
    else
    {
        brazehanVerticalHorizontal(&data);
    }
}

