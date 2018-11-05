/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:53:08 by jfarinha          #+#    #+#             */
/*   Updated: 2017/11/21 09:41:46 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *str, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	i;

	i = 0;
	if(!(tmp = (char *)malloc(sizeof(*tmp) * len + 1)))
		return (NULL);
	if (!str || !tmp)
		return (NULL);
	while (i < len)
	{
		tmp[i] = str[i + start];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
