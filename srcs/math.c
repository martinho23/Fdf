/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:06:59 by jfarinha          #+#    #+#             */
/*   Updated: 2024/10/23 21:18:51 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int     mini(int  a, int b)
{
    return ((a < b) ? a : b);
}

int     maxi(int  a, int b)
{
    return ((a > b) ? a : b);
}

float   minf(float a, float b)
{
    return ((a < b) ? a : b);
}

float   maxf(float  a, float b)
{
    return ((a > b) ? a : b);
}

double  mind(double a, double b)
{
    return ((a < b) ? a : b);
}

double  maxd(double a, double b)
{
    return ((a > b) ? a : b);
}

