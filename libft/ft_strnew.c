/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:45:40 by jfarinha          #+#    #+#             */
/*   Updated: 2017/11/21 09:39:38 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*tmp;

	if (!(tmp = (char *)malloc(sizeof(*tmp) * size + 1)))
		return (NULL);
	ft_bzero(tmp, size + 1);
	return (tmp);
}
