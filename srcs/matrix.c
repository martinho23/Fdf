/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.from>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 12:23:53 by jfarinha          #+#    #+#             */
/*   Updated: 2024/10/24 07:51:20 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../include/fdf.h>
#include "../libft/libft.h"

ptr_matrix4f	newMatrix4f(void)
{
	ptr_matrix4f	m;

	if (!(m = ft_memalloc(4 * sizeof(*m))))
		return (NULL);
	
    return (m);
}

void		delMatrix4(ptr_matrix4f m)
{
	if (m != NULL)
	{
		free(m);
		m = NULL;
	}
}

