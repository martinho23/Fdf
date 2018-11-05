/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:57:44 by jfarinha          #+#    #+#             */
/*   Updated: 2017/11/14 13:03:03 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *p_dst;
	unsigned char *p_src;

	p_dst = (unsigned char *)dst;
	p_src = (unsigned char *)src;
	while (n-- > 0)
		p_dst[n] = p_src[n];
	return (p_dst);
}
