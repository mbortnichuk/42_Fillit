/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_linkedlist.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 15:21:25 by mbortnic          #+#    #+#             */
/*   Updated: 2017/11/27 15:21:26 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* return a new tetrimino and give him a letter */
t_tetr	*ft_new(char **tetr, int nbr)
{
	t_tetr *ttt;

	ttt = NULL;
	ttt = (t_tetr*)malloc(sizeof(t_tetr));
	if (ttt == NULL)
		return (NULL);
	ttt->tetr = tetr;
	ttt->letter = 'A' + nbr;
	ttt->x = 0;
	ttt->y = 0;
	ttt->next = NULL;
	return (ttt);
}

/* split array to create a linked list of tetriminos */
t_tetr		*ft_create_linkedlist(char **arr)
{
	int			i;
	t_tetr	*st;
	t_tetr	*pt;

	i = 1;
	st = NULL;
	st = ft_new(ft_strsplit(arr[0], '\n'), 0);
	pt = st;
	while (i < ntet)
	{
		pt->next = ft_new(ft_strsplit(arr[i], '\n'), i);
		pt = pt->next;
		i++;
	}
	pt->next = NULL;
	return (st);
}