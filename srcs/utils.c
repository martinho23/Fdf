/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 19:09:29 by jfarinha          #+#    #+#             */
/*   Updated: 2019/07/15 18:39:48 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int		on_screen(t_vector3f pt)
{
	if (pt.x < (double)0 || pt.x > (double)WINW)
		return (0);
	if (pt.y < (double)0 || pt.y > (double)WINH)
		return (0);
	return (1);
}

int		mkcolor(t_uchar r, t_uchar g, t_uchar b)
{
	int		color;

	color = r;
	color = (color << 8) + g;
	color = (color << 8) + b;
	return (color);
}

