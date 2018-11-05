/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 10:28:07 by jfarinha          #+#    #+#             */
/*   Updated: 2017/11/17 10:28:11 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **a_lst, void (*del)(void *, size_t))
{
	del((*a_lst)->content, (*a_lst)->content_size);
	free(*a_lst);
	*a_lst = NULL;
}
