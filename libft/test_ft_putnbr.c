/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putnbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:31:43 by jfarinha          #+#    #+#             */
/*   Updated: 2018/04/18 14:37:15 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		size;

	if (argc == 2)
	{
		size = ft_putnbr(ft_atoi(argv[1]));
		printf("\nSize: %d\n", size);
	}
	else
		printf("Usage: test_ft_putnbr [nbr]\n");
	return (0);
}
