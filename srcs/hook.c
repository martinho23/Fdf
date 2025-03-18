/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 19:33:57 by jfarinha          #+#    #+#             */
/*   Updated: 2025/03/18 21:49:36 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42/MLX42.h>
#include <fdf.h>
#include <stdlib.h>

void	keyhook(void *p)
{
	t_sys *tmp;
	tmp = (t_sys *)p;
	if (mlx_is_key_down(tmp->mlx, MLX_KEY_ESCAPE))
		exit(0);
	if (mlx_is_key_down(tmp->mlx, MLX_KEY_UP))
		tmp->translate.y += 50 * tmp->mlx->delta_time;
	if (mlx_is_key_down(tmp->mlx, MLX_KEY_DOWN))
		tmp->translate.y -= 50 * tmp->mlx->delta_time;
	if (mlx_is_key_down(tmp->mlx, MLX_KEY_LEFT))
		tmp->translate.x -= 50 * tmp->mlx->delta_time;
	if (mlx_is_key_down(tmp->mlx, MLX_KEY_RIGHT))
		tmp->translate.x += 50 * tmp->mlx->delta_time;
	if (mlx_is_key_down(tmp->mlx, MLX_KEY_Q))
		tmp->translate.z -= 50 * tmp->mlx->delta_time;
	if (mlx_is_key_down(tmp->mlx, MLX_KEY_E))
		tmp->translate.z += 50 * tmp->mlx->delta_time;
    if (mlx_is_key_down(tmp->mlx, MLX_KEY_W))
        tmp->angle.x -= DEGREETORAD(45 * tmp->mlx->delta_time);
    if (mlx_is_key_down(tmp->mlx, MLX_KEY_S))
        tmp->angle.x += DEGREETORAD(44 * tmp->mlx->delta_time);
    if (mlx_is_key_down(tmp->mlx, MLX_KEY_A))
        tmp->angle.y -= DEGREETORAD(45 * tmp->mlx->delta_time);
    if (mlx_is_key_down(tmp->mlx, MLX_KEY_D))
        tmp->angle.y += DEGREETORAD(45 * tmp->mlx->delta_time);
}


int		mousehook(int key, int x, int y, void *p)
{
	((t_vector2i *)p)->x = x;
	((t_vector2i *)p)->y = y;
	return (key);
}
