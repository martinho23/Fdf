/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_uintmtoa_base.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 08:06:01 by jfarinha          #+#    #+#             */
/*   Updated: 2018/04/18 14:12:25 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int		main(int argc, const char *argv[])
{
	char	buff[65];
	int		size;

	 if (argc == 3)
	{
		size = ft_uintmtoa_base(ft_atoi(argv[1]), atoi(argv[2]), buff, STDBASE);
		printf("%s\nSize: %i\n", buff, size);
	}
	else
		printf("Usage: test_ft_uintmtoa_base nbr base\n");
	return (0);
}
