/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 18:15:11 by mrybak            #+#    #+#             */
/*   Updated: 2017/12/01 18:46:24 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (!alst && !new)
		return ;
	new->next = *alst;
	*alst = new;
	return ;
}

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *llist;

	if (!(llist = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		llist->content = NULL;
		llist->content_size = 0;
	}
	else
	{
		if ((llist->content = malloc(content_size)) == NULL)
		{
			free(llist);
			return (NULL);
		}
		ft_memcpy((llist->content), content, content_size);
		llist->content_size = content_size;
	}
	llist->next = NULL;
	return (llist);
}
