/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 21:09:00 by jfarinha          #+#    #+#             */
/*   Updated: 2024/10/23 21:16:43 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_vector2f clampVector2f(t_vector2f clampValue, t_vector2f max, t_vector2f min)
{
    clampValue.x = (clampValue.x > min.x) ? clampValue.x : min.x;
    clampValue.x = (clampValue.x < max.x) ? clampValue.x : max.x;
    clampValue.y = (clampValue.y > min.y) ? clampValue.y : min.y;
    clampValue.y = (clampValue.y < max.y) ? clampValue.y : max.y;
    
    return (clampValue);
}

t_vector2i clampVector2i(t_vector2i clampValue, t_vector2i min, t_vector2i max)
{
    clampValue.x = (clampValue.x > min.x) ? clampValue.x : min.x;
    clampValue.x = (clampValue.x < max.x) ? clampValue.x : max.x;
    clampValue.y = (clampValue.y > min.y) ? clampValue.y : min.y;
    clampValue.y = (clampValue.y < max.y) ? clampValue.y : max.y;
    
    return (clampValue);
}

t_vector3f clampVector3f(t_vector3f clampValue, t_vector3f min, t_vector3f max)
{
    clampValue.x = (clampValue.x > min.x) ? clampValue.x : min.x;
    clampValue.x = (clampValue.x < max.x) ? clampValue.x : max.x;
    clampValue.y = (clampValue.y > min.y) ? clampValue.y : min.y;
    clampValue.y = (clampValue.y < max.y) ? clampValue.y : max.y;
    clampValue.z = (clampValue.z > min.z) ? clampValue.z : min.z;
    clampValue.z = (clampValue.z < max.z) ? clampValue.z : max.z;
    
    return (clampValue);
}

t_vector3i clampVector3i(t_vector3i clampValue, t_vector3i min, t_vector3i max)
{
    clampValue.x = (clampValue.x > min.x) ? clampValue.x : min.x;
    clampValue.x = (clampValue.x < max.x) ? clampValue.x : max.x;
    clampValue.y = (clampValue.y > min.y) ? clampValue.y : min.y;
    clampValue.y = (clampValue.y < max.y) ? clampValue.y : max.y;
    clampValue.z = (clampValue.z > min.z) ? clampValue.z : min.z;
    clampValue.z = (clampValue.z < max.z) ? clampValue.z : max.z;
    
    return (clampValue);
}

t_vector4f clampVector4f(t_vector4f clampValue, t_vector4f min, t_vector4f max)
{
    clampValue.x = (clampValue.x > min.x) ? clampValue.x : min.x;
    clampValue.x = (clampValue.x < max.x) ? clampValue.x : max.x;
    clampValue.y = (clampValue.y > min.y) ? clampValue.y : min.y;
    clampValue.y = (clampValue.y < max.y) ? clampValue.y : max.y;
    clampValue.z = (clampValue.z > min.z) ? clampValue.z : min.z;
    clampValue.z = (clampValue.z < max.z) ? clampValue.z : max.z;
    clampValue.w = (clampValue.w > min.w) ? clampValue.w : min.w;
    clampValue.w = (clampValue.w < max.w) ? clampValue.w : max.w;
    
    return (clampValue);
}

t_vector4i clampVector4i(t_vector4i clampValue, t_vector4i min, t_vector4i max)
{
    clampValue.x = (clampValue.x > min.x) ? clampValue.x : min.x;
    clampValue.x = (clampValue.x < max.x) ? clampValue.x : max.x;
    clampValue.y = (clampValue.y > min.y) ? clampValue.y : min.y;
    clampValue.y = (clampValue.y < max.y) ? clampValue.y : max.y;
    clampValue.z = (clampValue.z > min.z) ? clampValue.z : min.z;
    clampValue.z = (clampValue.z < max.z) ? clampValue.z : max.z;
    clampValue.w = (clampValue.w > min.w) ? clampValue.w : min.w;
    clampValue.w = (clampValue.w < max.w) ? clampValue.w : max.w;
    
    return (clampValue);
}
