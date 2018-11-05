/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 23:38:42 by jfarinha          #+#    #+#             */
/*   Updated: 2017/11/27 23:13:40 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *element))
{
	t_list	*tmp;
	t_list	*newl;

	if (!(lst) || (tmp = f(lst)) == NULL)
		return (NULL);
	newl = tmp;
	while (lst->next)
	{
		lst = lst->next;
		if ((tmp->next = f(lst)) == NULL)
			return (NULL);
		tmp = tmp->next;
	}
	return (newl);
}
