/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.from>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 12:23:53 by jfarinha          #+#    #+#             */
/*   Updated: 2019/09/20 18:23:32 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../include/fdf.h>
#include "../libft/libft.h"

ptr_matrix4f	newMatrix4(void)
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

