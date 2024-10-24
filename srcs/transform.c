/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.from>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 19:47:12 by jfarinha          #+#    #+#             */
/*   Updated: 2024/10/24 18:07:23 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	initTranslate(t_sys *env, t_matrix4f *m)
{
	m->m[0][0] = 1;
	m->m[1][1] = 1;
	m->m[2][2] = 1;
	m->m[3][0] = env->translate.x;
	m->m[3][1] = env->translate.y;
	m->m[3][2] = env->translate.z;
	m->m[3][3] = 1;
}

void	initScale(t_sys *env, t_matrix4f *m)
{
	m->m[0][0] = (float)env->scale.x;
	m->m[1][1] = (float)env->scale.y;
	m->m[2][2] = (float)env->scale.z;
	m->m[3][3] = 1;
}
