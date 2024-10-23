/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:56:07 by jfarinha          #+#    #+#             */
/*   Updated: 2024/10/23 21:09:56 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <math.h>

void		ddaLine(t_sys *sys, t_vector2f a, t_vector2f b, int color)
{
    t_vector2f delta;
    t_vector2f linePoint;
    int         step;

    a = clampVector2f(a, MAKE_VECTOR2F(0, 0), MAKE_VECTOR2F((float)sys->screenSurface->size.x, (float)sys->screenSurface->size.y));
    b = clampVector2f(b, MAKE_VECTOR2F(0, 0), MAKE_VECTOR2F((float)sys->screenSurface->size.x, (float)sys->screenSurface->size.y));
    
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

    a = clampVector2i(a, MAKE_VECTOR2I(0, 0), env->screenSurface->size);
    b = clampVector2i(b, MAKE_VECTOR2I(0, 0), env->screenSurface->size);

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
                error += 2 * delta.y;
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
                error += 2 * delta.x;
            point.y ++;
        }

    }

}

