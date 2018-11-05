/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 23:02:06 by jfarinha          #+#    #+#             */
/*   Updated: 2017/11/13 09:04:15 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char *tmp;

	tmp = dest + ft_strlen(dest);
	while (*src && n-- > 0)
		*(tmp++) = *(src++);
	*tmp = '\0';
	return (dest);
}
