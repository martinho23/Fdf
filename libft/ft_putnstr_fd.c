/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 15:20:01 by jfarinha          #+#    #+#             */
/*   Updated: 2018/07/18 19:43:23 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int		ft_putnstr_fd(const char *str, size_t n, int fd)
{
	size_t	len;

	if ((fd < 0) && str)
		return (-1);
	len = ft_strlen(str);
	n = (n < len) ? n : len;
	write(fd, str, n);
	return ((int)n);
}
