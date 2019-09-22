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

#include "../includes/fdf.h"
#include "../libft/libft.h"

t_matrix4f	newMatrix4(void)
{
	int			i;
	t_matrix4f	m;

	if (!(m =ft_memalloc(4 * sizeof(*m))))
		return (NULL);
	i = 0;
	while (i < 4)
	{
		if (!(m[i] = ft_memalloc(4 * sizeof(**m))))
			return (NULL);
		i++;
	}
	return (m);
}

void		delMatrix4(t_matrix4f *m)
{
	int	i;

	if (m != NULL && *m != NULL && **m != NULL )
	{
		i = 0;
		while (i < 4)
		{
			free((*m)[i]);
			(*m)[i] = NULL;
			i++;
		}
	}
	if (m != NULL && *m != NULL)
	{
		free(*m);
		*m = NULL;
	}
}

