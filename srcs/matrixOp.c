/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrixOp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 19:05:09 by jfarinha          #+#    #+#             */
/*   Updated: 2024/10/27 22:26:47 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	matrix4Mul(ptr_matrix4f a, ptr_matrix4f b, ptr_matrix4f buff)
{
	int			i;
	int			j;

	if (buff && a && b)
	{
		i = 0;
		while (i < 4)
		{
			j = 0;
			while (j < 4)
			{
				buff->m[i][j] += a->m[i][0] * b->m[0][j];
				buff->m[i][j] += a->m[i][1] * b->m[1][j];
				buff->m[i][j] += a->m[i][2] * b->m[2][j];
				buff->m[i][j] += a->m[i][3] * b->m[3][j];
				j++;
			}
			i++;
		}
	}
}

t_vector4f	vec4Mul(t_matrix4f mat, ptr_vector4f vec)
{
	t_vector4f	tmp;
    tmp.x = vec->x * mat.m[0][0] + vec->y * mat.m[1][0] + \
			vec->z * mat.m[2][0] + mat.m[3][0];
	tmp.y = vec->x * mat.m[0][1] + vec->y * mat.m[1][1] + \
			vec->z * mat.m[2][1] + mat.m[3][1];
	tmp.z = vec->x * mat.m[0][2] + vec->y * mat.m[1][2] + \
			vec->z * mat.m[2][2] + mat.m[3][2];
	tmp.w =	vec->x * mat.m[0][3] + vec->y * mat.m[1][3] + \
            vec->z * mat.m[2][3] + mat.m[3][3];

	return (tmp);
}

t_vector4f	vec4MulHomogenous(t_matrix4f mat, ptr_vector4f vec)
{
	t_vector4f	tmp;
    tmp.x = vec->x * mat.m[0][0] + vec->y * mat.m[1][0] + \
			vec->z * mat.m[2][0] + mat.m[3][0];
	tmp.y = vec->x * mat.m[0][1] + vec->y * mat.m[1][1] + \
			vec->z * mat.m[2][1] + mat.m[3][1];
	tmp.z = vec->x * mat.m[0][2] + vec->y * mat.m[1][2] + \
			vec->z * mat.m[2][2] + mat.m[3][2];
	tmp.w =	vec->x * mat.m[0][3] + vec->y * mat.m[1][3] + \
            vec->z * mat.m[2][3] + mat.m[3][3];

    tmp.x /= tmp.w;
    tmp.y /= tmp.w;
    tmp.z /= tmp.w;

	return (tmp);
}
