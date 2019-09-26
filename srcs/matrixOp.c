/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrixOp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.from>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 19:05:09 by jfarinha          #+#    #+#             */
/*   Updated: 2019/09/23 19:49:58 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

void	matrix4Mul(t_matrix4f a, t_matrix4f b, t_matrix4f *buff)
{
	int			i;
	int			j;

	if (*buff && a && b)
	{
		i = 0;
		while (i < 4)
		{
			j = 0;
			while (j < 4)
			{
				(*buff)[i][j] += a[i][0] * b[0][j];
				(*buff)[i][j] += a[i][1] * b[1][j];
				(*buff)[i][j] += a[i][2] * b[2][j];
				(*buff)[i][j] += a[i][3] * b[3][j];
//				printf("A[%d][%d] = %f\n", i, j, a[i][j]);
//				printf("B[%d][%d] = %f\n", i, j, b[i][j]);
//				printf("Buff[%d][%d] = %f\n\n", i, j, (*buff)[i][j]);
				j++;
			}
			i++;
		}
	}
//	printf("\n");
}

t_vector3f	vec4Mul(t_matrix4f mat, t_vector3f vec)
{
	t_vector3f	tmp;
	double		w;

	if (mat)
	{
		tmp.x = vec.x * mat[0][0] + vec.y * mat[1][0] + \
				vec.z * mat[2][0] + mat[3][0];
		tmp.y = vec.x * mat[0][1] + vec.y * mat[1][1] + \
				vec.z * mat[2][1] + mat[3][1];
		tmp.z = vec.x * mat[0][2] + vec.y * mat[1][2] + \
				vec.z * mat[2][2] + mat[3][2];
		w =		vec.x * mat[0][3] + vec.y * mat[1][3] + \
				vec.z * mat[2][3] +  mat[3][3];
		if (w)
		{
			tmp.x /= w;
			tmp.y /= w;
			tmp.z /= w;
		}
		return (tmp);
	}
	return (vec);
}
