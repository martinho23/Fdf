/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:29:37 by jfarinha          #+#    #+#             */
/*   Updated: 2017/11/21 09:38:38 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *str, char (*f)(unsigned int, char))
{
	int		i;
	char	*tmp;

	i = 0;
	if (!str)
		return (NULL);
	if (!(tmp = (char *)malloc(sizeof(*tmp) * ft_strlen(str) + 1)))
		return (NULL);
	while (str[i])
	{
		tmp[i] = f(i, str[i]);
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
