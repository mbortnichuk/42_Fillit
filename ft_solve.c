/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 18:07:59 by mrybak            #+#    #+#             */
/*   Updated: 2017/12/01 18:44:58 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrt(int n)
{
	int s;

	s = 2;
	while (s * s < n)
		s++;
	return (s);
}

int		ft_solve_map(t_map *mapy, t_list *list)
{
	int			x;
	int			y;
	t_tetr		*tetr;

	if (list == NULL)
		return (1);
	y = 0;
	tetr = (t_tetr *)(list->content);
	while (y < mapy->size - tetr->h + 1)
	{
		x = 0;
		while (x < mapy->size - tetr->w + 1)
		{
			if (ft_placement(tetr, mapy, x, y))
			{
				if (ft_solve_map(mapy, list->next))
					return (1);
				else
					ft_place_piece(tetr, mapy, ft_new_coord(x, y), '.');
			}
			x++;
		}
		y++;
	}
	return (0);
}

t_map	*ft_solution(t_list *list)
{
	t_map	*mapy;
	int		size;

	size = ft_sqrt(ft_lstcount(list) * 4);
	mapy = ft_create_mapy(size);
	while (!ft_solve_map(mapy, list))
	{
		size++;
		ft_free_mapy(mapy);
		mapy = ft_create_mapy(size);
	}
	return (mapy);
}
