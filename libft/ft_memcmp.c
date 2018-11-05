/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:54:24 by jfarinha          #+#    #+#             */
/*   Updated: 2017/11/14 13:03:29 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *p1, const void *p2, size_t n)
{
	int		cmp;

	while (n-- > 0)
	{
		cmp = *(unsigned char *)p1++ - *(unsigned char *)p2++;
		if (cmp)
			return (cmp);
	}
	return (0);
}
