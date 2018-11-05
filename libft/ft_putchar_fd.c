/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:13:59 by jfarinha          #+#    #+#             */
/*   Updated: 2018/07/18 19:42:04 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static void	putchar_fd(int c, int fd)
{
	write(fd, &c, 1);
}

int		ft_putchar_fd(int c, int fd)
{
	if (c <= 0x7F && fd >= 0)
		putchar_fd(c, fd);
	else if (c <= 0x7FF && fd >= 0)
	{
		putchar_fd((c >> 6) + 0xC0, fd);
		putchar_fd((c & 0x3F) + 0x80, fd);
		return (2);
	}
	else if (c <= 0xFFFF && fd >= 0)
	{
		putchar_fd((c >> 12) + 0xE0, fd);
		putchar_fd(((c >> 6) & 0x3F) + 0x80, fd);
		putchar_fd((c & 0x3F) + 0x80, fd);
		return (3);
	}
	else if (c <= 0x10FFFF && fd >= 0)
	{
		putchar_fd((c >> 18) + 0xF0, fd);
		putchar_fd(((c >> 12) & 0x3F) + 0x80, fd);
		putchar_fd(((c >> 6) & 0x3F) + 0x80, fd);
		putchar_fd((c & 0x3F) + 0x80, fd);
		return (4);
	}
	return ((fd >= 0) ? (1) : (-1));
}
