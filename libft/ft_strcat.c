/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 21:40:06 by jfarinha          #+#    #+#             */
/*   Updated: 2017/11/13 08:54:04 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	char *tmp;

	tmp = dest + ft_strlen(dest);
	while (*src)
		*(tmp++) = *(src++);
	*tmp = '\0';
	return (dest);
}
