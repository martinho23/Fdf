/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 13:26:44 by jfarinha          #+#    #+#             */
/*   Updated: 2018/04/19 11:59:58 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int nbr)
{
	char	array[ft_imtoalen_base(nbr, 10) + 1];
	int		signe;

	signe = (nbr < 0) ? 0 : 1;
	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	nbr = (nbr < 0) ? (nbr * -1) : nbr;
	ft_uimtoa_base(nbr, 10,  array, BASE10);
	return (signe == 0) ? (ft_strjoin("-", array)) : (ft_strdup(array));
}
