/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:43:32 by jfarinha          #+#    #+#             */
/*   Updated: 2017/11/27 23:13:40 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t len;
	size_t i;

	len = ft_strlen(s2);
	i = 0;
	if (!s1)
		((char *)s1)[2]++;
	if (!n || !s2 || len > n)
		return (NULL);
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[i] && i <= (n - len))
	{
		if (ft_strncmp((char *)&s1[i], (char *)s2, len) == 0)
			return ((char *)&s1[i]);
		i++;
	}
	return (NULL);
}
