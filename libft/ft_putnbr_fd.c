/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:31:27 by jfarinha          #+#    #+#             */
/*   Updated: 2018/04/19 12:00:14 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnbr_fd(int nbr, int fd)
{
	long	lnbr;
	int		len;
	char	nbra[ft_imtoalen_base(nbr, 10) + 1];

	if (fd < 0)
		return (-1);
	lnbr = (long)nbr;
	len = 0;
	if (lnbr < 0)
	{
		lnbr *= -1;
		ft_putchar_fd('-', fd);
	}
	len = ft_uimtoa_base(lnbr, 10, nbra, BASE10);
	ft_putstr_fd(nbra, fd);
	return ((nbr < 0) ? (len + 1) : len);
}
