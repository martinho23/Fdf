/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:49:42 by jfarinha          #+#    #+#             */
/*   Updated: 2017/11/21 09:30:33 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
 	t_list	*tmp;

	if (!(tmp = (t_list *)malloc(sizeof(*tmp))))
		return (NULL);
	if (!(tmp->content = ft_memalloc(content_size)))
		return (NULL);
	if (content)
	{
		tmp->content_size = content_size;
		ft_memcpy(tmp->content, content, content_size);
	}
	else
	{
		tmp->content = NULL;
		tmp->content_size = 0;
	}
	tmp->next = NULL;
	return (tmp);
}
