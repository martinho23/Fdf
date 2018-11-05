/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uimtoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 08:52:42 by jfarinha          #+#    #+#             */
/*   Updated: 2018/07/18 19:36:53 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	proc(uintmax_t nbr, size_t b, int step, char *ar, char *chars)
{
	int	size;

	size = 0;
	size = (step > size) ? step : size;
	if (nbr > (b - 1))
		size = proc((nbr / b), b, (step + 1), ar, chars);
	ar[size - step] = chars[nbr % b];
	return (size);
}

int			ft_uimtoa_base(uintmax_t nbr, size_t b, char *ar, char *cl)
{
	int		size;

	if (b < 2 || b > ft_strlen(cl))
		return (-1);
	size = proc(nbr, b, 0, ar, cl);
	ar[size + 1] = '\0';
	return (size + 1);
}
