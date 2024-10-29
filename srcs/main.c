/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 17:24:39 by jfarinha          #+#    #+#             */
/*   Updated: 2024/10/29 21:28:24 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <libft.h>
#include <stdio.h>

# define BPP sizeof(int32_t)

int printhi(void)
{
    printf("Hello World!");
    return(1);
}

int main(int ac, char **av) {
  t_sys env;

  ft_thrower(ac != 2, "Usage: You must specify a map file to load!");
  env.mlx = mlx_init(WINW, WINH, WINNAME, true);
  ft_thrower(!env.mlx, "Couldn't initialise MLX");
  load(av[1], &env);
  ft_thrower(env.size_x <= 0 || env.size_y <= 0, "Map error: wrong format!");
  env.projection = loadProjection();
  env.translate.x = (-0.5f * env.size_x * GRIDSCALE) + (0.5f * GRIDSCALE);
  env.translate.y = (-0.5f * env.size_y * GRIDSCALE) + (0.5f * GRIDSCALE);
  env.translate.z = (env.size_z * 5);
  env.scale.x = 1;
  env.scale.y = 1;
  env.scale.z = 1;
  printf("print done!\n");
  initScreenSurface(&env, WINW, WINH);
  ft_memset(env.screenSurface.pixels, 255, env.screenSurface.height * env.screenSurface.width * BPP);
 // drawBuffer(&env);
  mlx_key_hook(env.mlx, keyhook, &env);
   //mlx_loop_hook(env.mlx, draw, &env);

  mlx_loop(env.mlx);
  return (0);
}
