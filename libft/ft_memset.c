/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:12:10 by jfarinha          #+#    #+#             */
/*   Updated: 2018/07/18 19:35:26 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *p, int c, size_t n)
{
	unsigned char *tmp;

	tmp = (unsigned char *)p;
	while (n-- > 0)
		*(tmp++) = (unsigned char)c;
	return (p);
}
