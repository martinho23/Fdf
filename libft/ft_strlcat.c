/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 09:05:11 by jfarinha          #+#    #+#             */
/*   Updated: 2017/11/14 13:07:20 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(dst);
	while (src[i] && (len + i + 1) < n)
	{
		dst[len + i] = src[i];
		i++;
	}
	dst[len + i] = '\0';
	if (len > n)
		return (ft_strlen(src) + n);
	return (len + ft_strlen(src));
}
