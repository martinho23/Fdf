/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 19:33:57 by jfarinha          #+#    #+#             */
/*   Updated: 2019/09/22 13:16:21 by jfarinha         ###   ########.fr       */
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
		tmp->translate.y -= 10;
	if (keycode == XK_DOWN)
		tmp->translate.y += 10;
	if (keycode == XK_LEFT)
		tmp->translate.x -= 10;
	if (keycode == XK_RIGHT)
		tmp->translate.x += 10;
	if (keycode == XK_KP_ADD)
		tmp->translate.z += 0.9;
	if (keycode == XK_KP_SUB)
		tmp->translate.z -= 0.9;
	draw(tmp);
	return (0);
}

int		mousehook(int keycode, int x, int y, void *p)
{
	((t_point *)p)->x = x;
	((t_point *)p)->y = y;
	return (keycode);
}
