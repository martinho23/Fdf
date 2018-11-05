/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:14:42 by jfarinha          #+#    #+#             */
/*   Updated: 2017/11/21 09:30:59 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char *tmp;

	if (!(tmp = (unsigned char *)malloc(sizeof(*tmp) * size)))
		return (NULL);
	ft_bzero(tmp, size);
	return (tmp);
}
