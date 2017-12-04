/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freeitall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 18:02:18 by mrybak            #+#    #+#             */
/*   Updated: 2017/12/01 18:46:40 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_free_struct(t_tetr *tetr)
{
	int y;

	y = 0;
	while (y < tetr->h)
	{
		ft_memdel((void **)(&(tetr->pos[y])));
		y++;
	}
	ft_memdel((void **)(&(tetr->pos)));
	ft_memdel((void **)&tetr);
}

t_list	*ft_free_tetr_list(t_list *list)
{
	t_tetr	*tetr;
	t_list	*next;

	while (list)
	{
		tetr = (t_tetr *)list->content;
		next = list->next;
		ft_free_struct(tetr);
		ft_memdel((void **)&list);
		list = next;
	}
	return (NULL);
}

void	ft_free_mapy(t_map *mapy)
{
	int i;

	i = 0;
	while (i < mapy->size)
	{
		ft_memdel((void **)&(mapy->arr[i]));
		i++;
	}
	ft_memdel((void **)&(mapy->arr));
	ft_memdel((void **)&mapy);
}
