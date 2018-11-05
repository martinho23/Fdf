/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:23:42 by jfarinha          #+#    #+#             */
/*   Updated: 2017/11/16 18:23:23 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	ft_lstdel(t_list **a_lst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	while (*a_lst)
	{
		tmp = (*a_lst)->next;
		del((*a_lst)->content, (*a_lst)->content_size);
		free((*a_lst));
		*a_lst = tmp;
	}
	*a_lst = NULL;
}
