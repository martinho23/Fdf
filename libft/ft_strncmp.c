/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:42:18 by jfarinha          #+#    #+#             */
/*   Updated: 2017/11/13 13:47:13 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1 || *s2) && n-- > 0)
	{
		if (*s1++ != *s2++)
			return (((unsigned char)*(s1 - 1)) - ((unsigned char)*(s2 - 1)));
	}
	return (0);
}
