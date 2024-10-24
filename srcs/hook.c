/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 19:33:57 by jfarinha          #+#    #+#             */
/*   Updated: 2024/10/24 07:58:56 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fdf.h>
#include <stdio.h>
#include <stdlib.h>

int		keyhook(int keycode, void *p)
{
	t_sys *tmp;
	tmp = (t_sys *)p;
    mlx_do_key_autorepeaton(tmp->mlx);
	if (keycode == XK_ESC)
		exit(0);
	if (keycode == XK_UP)
		tmp->translate.y -= 10;
	if (keycode == XK_DOWN)
		tmp->translate.y += 10;
	if (keycode == XK_LEFT)
		tmp->translate.x -= 10;
	if (keycode == XK_RIGHT)
		tmp->translate.x += 10;
	if (keycode == XK_A)
		tmp->translate.z -= 10;
	if (keycode == XK_E)
		tmp->translate.z += 10;
    draw(tmp);
	return (0);
}

int		mousehook(int keycode, int x, int y, void *p)
{
	((t_vector2i *)p)->x = x;
	((t_vector2i *)p)->y = y;
	return (keycode);
}
