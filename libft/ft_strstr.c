/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:58:12 by jfarinha          #+#    #+#             */
/*   Updated: 2017/11/27 23:13:40 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int i;

	i = 0;
	if (s2[i] == '\0')
		return ((char *)s1);
	while (*s1)
	{
		while (*(s1 + i) == s2[i])
		{
			if (!(s2[i + 1]))
				return ((char *)s1);
			i++;
		}
		i = 0;
		s1++;
	}
	return (NULL);
}
