/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_uimtoalen_base.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 10:43:46 by jfarinha          #+#    #+#             */
/*   Updated: 2018/04/18 10:55:55 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		main(int argc, const char *argv[])
{
	int		size;

	if (argc == 3)
	{
		size = ft_uimtoalen_base(ft_atoi(argv[1]), ft_atoi(argv[2]));
		printf("Size: %d\n", size);
	}
	else
		printf("Usage: ./test_ft_uimtoalen_base nbr base\n");
	return (0);
}
