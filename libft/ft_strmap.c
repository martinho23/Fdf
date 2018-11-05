/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:40:31 by jfarinha          #+#    #+#             */
/*   Updated: 2017/11/21 09:38:25 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *str, char (*f)(char))
{
	char	*tmp;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	if (!(tmp = (char *)(malloc(sizeof(*tmp) * ft_strlen(str) + 1))))
		return (NULL);
	while (str[i])
	{
		tmp[i] = f(str[i]);
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
