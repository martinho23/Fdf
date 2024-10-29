/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenBuffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:05:14 by jfarinha          #+#    #+#             */
/*   Updated: 2024/10/29 23:06:02 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <libft.h>
#include <stdio.h>

int drawBuffer(t_sys *env)
{
    if(mlx_image_to_window(env->mlx, env->screenSurface, 0, 0) < 0)
        ft_thrower(true,(char *)mlx_strerror(mlx_errno));
    return (0);
}

mlx_image_t *initScreenSurface(t_sys *env, t_size width, t_size height) {

    mlx_image_t *screenSurface;
    ft_thrower(!env->mlx, "Can't create surface because MLX pointer is NULL\n");


    screenSurface = NULL;
    screenSurface = mlx_new_image(env->mlx, width, height);
    ft_thrower(!screenSurface, "mlx couldn't create Screen, Surface\n");

    return screenSurface;
}

void resizeScreenSurface(int32_t width, int32_t height, void *sys) {
    t_sys *env = (t_sys *)sys;
    freeScreenSurface(env);
    initScreenSurface(env, width, height);

}

void freeScreenSurface(t_sys *env) 
{
  mlx_image_t *screenSurface = env->screenSurface;

  if (screenSurface)
    mlx_delete_image(env->mlx, screenSurface);
}

void clearScreenSurface(t_sys *env, int color)
{
    mlx_image_t *screen = env->screenSurface;
    t_vector2ui iterator;
    uint8_t *dest;


    uint32_t fillColor = color;
 //   fillColor = fillColor << 32 | color;
    iterator.y = 0;
    (void)dest;
    (void)fillColor;

    while(iterator.y < screen->height)
    {
        int line = iterator.y * screen->width;
        (void)line;
        iterator.x = 0;

        while(iterator.x < screen->width)
        {
            
           // dest = &screen->pixels[(line + (iterator.x * (sizeof(uint32_t))))];
            //*(uint32_t *)dest = fillColor;
            mlx_put_pixel(screen, iterator.x, iterator.y, 0x181818FF);
            iterator.x ++;
        }

        iterator.y ++;
    }
    printf("Iterator Y: %u Iterator X: %u\n", iterator.y, iterator.x);
}

void putPixelToScreenSurface(mlx_image_t *screen, t_vector2i point, int color)
{
    uint8_t *dest;

    dest = (screen->pixels + (point.y * screen->width + (point.x + sizeof(uint32_t))));
    *(unsigned int *)dest = color;
}


