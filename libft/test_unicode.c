/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_unicode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 18:34:24 by jfarinha          #+#    #+#             */
/*   Updated: 2018/04/23 13:50:40 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <wchar.h>

int		main(void)
{
	wchar_t	str[200] = /*L"0123456789" L"*/L"ɐɑɒɓɔɕɖɗɘəɚɛɜɝɞɟ";
	int		size;
//	wchar_t	*str = NULL;

	size = ft_putwstr_fd(str, 1);
	printf("\nSize = %i\n", size);
	size = ft_wstrlen(str);
	printf("\nSize = %i\n", size);
	return (0);
}
