/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:12:00 by jfarinha          #+#    #+#             */
/*   Updated: 2018/07/18 19:58:03 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		countwords(const char *str, char c)
{
	int		words;
	int		i;

	words = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static	void	split(char **tmp, const char *str, int words, char c)
{
	int		s;
	int		e;
	int		i;

	s = 0;
	e = 0;
	i = 0;
	while (i < words)
	{
		while (str[s] && str[s] == c)
			s++;
		e = s + 1;
		while (str[e] && str[e] != c)
			e++;
		tmp[i] = ft_strsub(str, s, (e - s));
		s = e;
		e = 0;
		i++;
	}
}

char			**ft_strsplit(const char *str, char c)
{
	int		words;
	char	**tmp;

	if (!str)
		return (NULL);
	words = countwords(str, c);
	if (!(tmp = (char **)malloc(sizeof(*tmp) * (words + 1))))
		return (NULL);
	split(tmp, str, words, c);
	tmp[words] = NULL;
	return (tmp);
}
