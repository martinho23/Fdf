/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atoim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 20:58:54 by jfarinha          #+#    #+#             */
/*   Updated: 2018/07/15 21:11:02 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./libft.h"

int		main(int argc, char **argv)
{
	if (argc == 2)
		printf("output %jd\n", ft_atoim(argv[1]));
	return (0);
}
