/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfreejoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 19:25:03 by jfarinha          #+#    #+#             */
/*   Updated: 2018/01/12 14:10:11 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
char	*ft_strfreejoin(char *s1, const char *s2)
{
	char	*tmp;

	if (!s1 && !s2)
		return (NULL);
	if (!(tmp = (char *)malloc(sizeof(*tmp) * \
				(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	ft_strcpy(tmp, s1);
	ft_strcat(tmp, s2);
	ft_strdel(&s1);
	return (tmp);
}
