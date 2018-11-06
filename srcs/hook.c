/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 19:33:57 by jfarinha          #+#    #+#             */
/*   Updated: 2018/11/06 19:11:23 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fdf.h>
#include <stdlib.h>

int		keyhook(int keycode, void *p)
{
	(void)p;
	if (keycode == XK_ESC || keycode == MK_ESC)
		exit(0);
	return (0);
}

int		mousehook(int keycode, int x, int y, void *p)
{
	((t_point *)p)->x = x;
	((t_point *)p)->y = y;
	return (keycode);
}
