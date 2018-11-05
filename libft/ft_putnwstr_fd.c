/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnwstr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 04:01:54 by jfarinha          #+#    #+#             */
/*   Updated: 2018/07/18 19:42:59 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnwstr_fd(const wchar_t *str, size_t n, int fd)
{
	int len;

	if (fd > 0 && str)
	{
		len = 0;
		while (*str && (n > (size_t)len))
			len += ft_putchar_fd(*str++, fd);
		return (len);
	}
	return (-1);
}
