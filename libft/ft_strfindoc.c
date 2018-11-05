/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfindoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 10:00:45 by jfarinha          #+#    #+#             */
/*   Updated: 2018/01/11 10:25:15 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strfindoc(const char *str, char oc)
{
	int		count;

	count = 0;
	while (*str)
		if (*str++ == oc)
			count++;
	return (count);
}
