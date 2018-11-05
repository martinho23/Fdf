/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 08:06:01 by jfarinha          #+#    #+#             */
/*   Updated: 2018/04/18 16:58:10 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
int		main(void)
{
	char	buff[65];
	size_t	size;
	void	*p;

	p = &size;
	size = ft_uimtoa_base((intptr_t)p, 16, buff, BASE16);
	printf("0x%s\n", buff);
	printf("%#.15lx\n", (intptr_t)p);
	return (0);
}
