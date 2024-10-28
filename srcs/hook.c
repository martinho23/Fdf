/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 19:33:57 by jfarinha          #+#    #+#             */
/*   Updated: 2024/10/28 22:13:29 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42/MLX42.h>
#include <fdf.h>
#include <stdlib.h>

void	keyhook(mlx_key_data_t key, void *p)
{
	t_sys *tmp;
	tmp = (t_sys *)p;
	if (key.key == MLX_KEY_ESCAPE)
		exit(0);
	if (key.key == XK_UP)
		tmp->translate.y -= 10;
	if (key.key == XK_DOWN)
		tmp->translate.y += 10;
	if (key.key == XK_LEFT)
		tmp->translate.x -= 10;
	if (key.key == XK_RIGHT)
		tmp->translate.x += 10;
	if (key.key == XK_A)
		tmp->translate.z -= 10;
	if (key.key == XK_E)
		tmp->translate.z += 10;
}

int		mousehook(int key, int x, int y, void *p)
{
	((t_vector2i *)p)->x = x;
	((t_vector2i *)p)->y = y;
	return (key);
}
