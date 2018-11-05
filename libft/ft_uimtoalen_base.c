/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uimtoalen_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 10:36:36 by jfarinha          #+#    #+#             */
/*   Updated: 2018/07/18 19:37:16 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_uimtoalen_base(uintmax_t nbr, size_t b)
{
	int		i;

	i = 1;
	while (nbr >= b)
	{
		nbr /= b;
		i++;
	}
	return (i);
}
