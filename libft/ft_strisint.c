/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 05:19:57 by jfarinha          #+#    #+#             */
/*   Updated: 2018/07/16 06:08:08 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strisint(const char *str)
{
	int i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (!(str[i] == '-' || str[i] == '+' || ft_isdigit(str[i])))
		return (0);
	if (str)
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
				return (0);
		i++;
	}
	return (1);
}
