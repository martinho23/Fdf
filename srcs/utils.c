/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 19:09:29 by jfarinha          #+#    #+#             */
/*   Updated: 2018/11/04 19:30:18 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int		on_screen(t_point pt)
{
	if (pt.x < 0 || pt.x > WINW)
		return (0);
	if (pt.y < 0 || pt.y > WINH)
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
