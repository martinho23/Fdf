/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 19:59:44 by jfarinha          #+#    #+#             */
/*   Updated: 2017/11/20 13:28:01 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	whitespaces(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char		*ft_strtrim(const char *str)
{
	int		i;
	int		j;
	char	*tmp;

	if (!str)
		return (NULL);
	i = 0;
	j = ft_strlen(str);
	while (str[i] && whitespaces(str[i]))
		i++;
	while (whitespaces(str[j - 1]) && (j - 1) > 0)
		j--;
	if (j - i < 0)
		i = 1;
	tmp = ft_strsub(str, i, (j - i));
	return (tmp);
}
