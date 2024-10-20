/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 17:24:39 by jfarinha          #+#    #+#             */
/*   Updated: 2019/09/26 19:10:35 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <libft.h>
#include <math.h>
#include <mlx.h>
#include <stdio.h>

int drawBuffer(t_sys *env)
{
    mlx_put_image_to_window(env->mlx, env->win, env->screenSurface->image, 0, 0);
    SWAPSCREENSURFACE(env->screenSurface);
    clearScreenSurface(env);

    return (0);
}

int main(int ac, char **av) {
  t_sys env;

  ft_thrower(ac != 2, "Usage: You must specify a map file to load!");
  env.mlx = mlx_init();
  env.win = mlx_new_window(env.mlx, WINW, WINH, "FDF");
  load(av[1], &env);
  ft_thrower(env.size_x <= 0 || env.size_y <= 0, "Map error: wrong format!");
  env.a = (WINH / WINW);
  env.f = 1 / tan(FOV * 3.14159f / 180.0f * 0.5f);
  env.q = ZFAR / (ZFAR - ZNEAR);
  printf("a: %f, f: %f q: %f\n", env.a, env.f, env.q);
  env.projection = loadProjection(env.a, env.f, env.q);
  env.translate.x = 0;
  env.translate.y = 0;
  env.translate.z = 1;
  env.scale.x = 1;
  env.scale.y = 1;
  env.scale.z = 1;
  printf("print done!\n");
  env.screenSurface = initScreenSurface(&env, WINW, WINH);
  mlx_loop_hook(env.win, draw, &env);
  mlx_expose_hook(env.win, draw, &env);
  mlx_key_hook(env.win, keyhook, &env);
  mlx_loop(env.mlx);
  return (0);
}
