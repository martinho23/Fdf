/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 19:33:57 by jfarinha          #+#    #+#             */
/*   Updated: 2019/09/23 19:55:32 by jfarinha         ###   ########.fr       */
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
	if (keycode == XK_ESC)
		exit(0);
	if (keycode == XK_UP)
		tmp->translate.y -= 0.1;
	if (keycode == XK_DOWN)
		tmp->translate.y += 0.1;
	if (keycode == XK_LEFT)
		tmp->translate.x -= 0.1;
	if (keycode == XK_RIGHT)
		tmp->translate.x += 0.1;
	if (keycode == XK_KP_ADD)
		tmp->translate.z -= 0.1;
	if (keycode == XK_KP_SUB)
		tmp->translate.z += 0.1;
	draw(tmp);
	return (0);
}

int		mousehook(int keycode, int x, int y, void *p)
{
	((t_vector2i *)p)->x = x;
	((t_vector2i *)p)->y = y;
	return (keycode);
}
