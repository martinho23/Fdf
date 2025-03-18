/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 17:24:39 by jfarinha          #+#    #+#             */
/*   Updated: 2025/03/18 21:48:08 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <libft.h>
#include <memory.h>
#include <stdio.h>

# define BPP sizeof(int32_t)

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
  env.angle.x = DEGREETORAD(360);
  env.angle.y = DEGREETORAD(0);
  env.angle.z = DEGREETORAD(0);
  env.screenSurface = initScreenSurface(&env, WINW, WINH);
  drawBuffer(&env);
  mlx_loop_hook(env.mlx, keyhook, &env);
  mlx_loop_hook(env.mlx, draw, &env);
  printf("print done!\n");
  mlx_loop(env.mlx);

  return (0);
}
