/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 19:33:57 by jfarinha          #+#    #+#             */
/*   Updated: 2024/12/27 20:07:19 by jfarinha         ###   ########.fr       */
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
}


int		mousehook(int key, int x, int y, void *p)
{
	((t_vector2i *)p)->x = x;
	((t_vector2i *)p)->y = y;
	return (key);
}
