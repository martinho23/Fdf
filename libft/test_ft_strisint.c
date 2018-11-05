/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strisint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 05:24:38 by jfarinha          #+#    #+#             */
/*   Updated: 2018/07/16 05:35:17 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./libft.h"

int		main(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (ft_strisint(argv[i]))
			printf("%s Is a valid Int!\n", argv[i]);
		else
			printf("%s Is not a valid Int!\n", argv[i]);
		i++;
	}
	return (0);
}
