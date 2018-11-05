/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:50:10 by jfarinha          #+#    #+#             */
/*   Updated: 2017/11/27 23:13:40 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char *tmp;

	tmp = NULL;
	while (*str)
	{
		if (*(str++) == c)
			tmp = (char *)str - 1;
	}
	if (c == '\0')
		return ((char *)str);
	return (tmp);
}
