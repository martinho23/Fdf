/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 10:45:59 by jfarinha          #+#    #+#             */
/*   Updated: 2018/04/23 13:55:56 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putwstr_fd(const wchar_t *str, int fd)
{
	size_t	len;

	if ((fd < 0) && str)
		return (-1);
	len = 0;
	while(str && *str)
		len += ft_putchar_fd(*str++, fd);
	return (len);
}
