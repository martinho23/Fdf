/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 19:09:29 by jfarinha          #+#    #+#             */
/*   Updated: 2018/11/06 22:49:58 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <math.h>
#include <stdio.h>

int		on_screen(t_point pt)
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

t_point	vectop(t_vector3f v, t_vector3f c)
{
	t_point		p;
	t_vector3f	d;

	d.x = cos(v.y) * (sin(v.z) * (v.y - c.y) + cos(v.z) * (v.x - c.x) - sin(v.y) * (v.z - c.z));
	d.y = sin(v.x) * (cos(v.y) * (v.z - c.z) + sin(v.y) * (sin(v.z) * (v.y - c.y) + cos(v.z) * (v.x - c.x))) + cos(v.x) * (cos(v.z) * (v.y - c.y) - sin(v.z) * (v.x - c.x));
	d.z = cos(v.x) * (cos(v.y) * (v.z - c.z) + sin(v.y) * (sin(v.z) * (v.y - c.y) + cos(v.z) * (v.x - c.x))) - sin(v.x) * (cos(v.z) * (v.y - c.y) - sin(v.z) * (v.x - c.x));
	p.x = round((1 / d.z) * d.x + (WINW / 2));
	p.y = round((1 / d.z) * d.y + (WINH / 2));
	p.x = (p.x < (double)0) ? (double)-1 : p.x;
	p.x = (p.x > (double)WINW) ? (double)(WINW + 1) : p.x;
	p.y = (p.y < (double)0) ? (double)-1 : p.y;
	p.y = (p.y > (double)WINH) ? (double)(WINH + 1) : p.y;
	return (p);
}
