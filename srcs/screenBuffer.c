/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenBuffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:05:14 by jfarinha          #+#    #+#             */
/*   Updated: 2024/10/29 21:30:27 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <libft.h>

int drawBuffer(t_sys *env)
{
    if(mlx_image_to_window(env->mlx, &env.screenSurface, 0, 0) < 0)
        ft_thrower(true,(char *)mlx_strerror(mlx_errno));

    return (0);
}

void initScreenSurface(t_sys *env, t_size width, t_size height) {

    ft_thrower(!env->mlx, "Can't create surface because MLX pointer is NULL\n");


    env->screenSurface = mlx_new_image(env->mlx, width, height);
    ft_thrower(!env->screenSurface, "mlx couldn't create Screen, Surface\n");
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
    mlx_image_t screen = env->screenSurface;
    t_vector2ui iterator;
    uint8_t *dest;


    long int fillColor = color;
    fillColor = fillColor << 32 | color;
    iterator.y = 0;
    while(iterator.y < screen.height)
    {
        int line = iterator.y * screen.width;
        iterator.x = 0;

        while(iterator.x < screen.width / 2)
        {
            
            dest = screen.pixels + (line + (iterator.x * (sizeof(uint32_t) * 2)));
            *(long int*)dest = fillColor;
            iterator.x ++;
        }

        iterator.y ++;
    }
}

void putPixelToScreenSurface(mlx_image_t screen, t_vector2i point, int color)
{
    uint8_t *dest;

    dest = (screen.pixels + (point.y * screen.width + (point.x + sizeof(uint32_t))));
    *(unsigned int *)dest = color;
}


