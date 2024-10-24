/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:06:59 by jfarinha          #+#    #+#             */
/*   Updated: 2024/10/23 23:35:55 by jfarinha         ###   ########.fr       */
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

t_vector2i          divVector2iByScalar(t_vector2i vector, int scalar)
{
    vector.x /= scalar;
    vector.y /= scalar;

	return (vector);
}

t_vector2f          divVector2fByScalar(t_vector2f vector, float scalar)
{
    vector.x /= scalar;
    vector.y /= scalar;

	return (vector);
}

t_vector3i          divVector3iByScalar(t_vector3i vector, int scalar)
{
    vector.x /= scalar;
    vector.y /= scalar;
    vector.z /= scalar;

	return (vector);
}

t_vector3f          divVector3fByScalar(t_vector3f vector, float scalar)
{
    vector.x /= scalar;
    vector.y /= scalar;
    vector.z /= scalar;

	return (vector);
}

t_vector4i          divVector4iByScalar(t_vector4i vector, int scalar)
{
    vector.x /= scalar;
    vector.y /= scalar;
    vector.z /= scalar;
    vector.w /= scalar;

	return (vector);
}

t_vector4f          divVector4fByScalar(t_vector4f vector, float scalar)
{
    vector.x /= scalar;
    vector.y /= scalar;
    vector.z /= scalar;
    vector.w /= scalar;

	return (vector);
}

t_vector2i          mulVector2iByScalar(t_vector2i vector, int scalar)
{
    vector.x *= scalar;
    vector.y *= scalar;

	return (vector);
}

t_vector2f          mulVector2fByScalar(t_vector2f vector, float scalar)
{
    vector.x *= scalar;
    vector.y *= scalar;

	return (vector);
}

t_vector3i          mulVector3iByScalar(t_vector3i vector, int scalar)
{
    vector.x *= scalar;
    vector.y *= scalar;
    vector.z *= scalar;

	return (vector);
}

t_vector3f          mulVector3fByScalar(t_vector3f vector, float scalar)
{
    vector.x *= scalar;
    vector.y *= scalar;
    vector.z *= scalar;

	return (vector);
}

t_vector4i          mulVector4iByScalar(t_vector4i vector, int scalar)
{
    vector.x *= scalar;
    vector.y *= scalar;
    vector.z *= scalar;
    vector.w *= scalar;

	return (vector);
}

t_vector4f          mulVector4fByScalar(t_vector4f vector, float scalar)
{
    vector.x *= scalar;
    vector.y *= scalar;
    vector.z *= scalar;
    vector.w *= scalar;
    
	return (vector);
}
