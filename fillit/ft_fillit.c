/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:18:42 by mbortnic          #+#    #+#             */
/*   Updated: 2017/12/01 18:44:51 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map	*ft_create_mapy(int n)
{
	t_map	*mapy;
	int		i;
	int		j;

	mapy = (t_map *)ft_memalloc(sizeof(t_map));
	mapy->size = n;
	mapy->arr = (char **)ft_memalloc(sizeof(char *) * n);
	i = 0;
	while (i < n)
	{
		mapy->arr[i] = ft_strnew(n);
		j = 0;
		while (j < n)
		{
			mapy->arr[i][j] = '.';
			j++;
		}
		i++;
	}
	return (mapy);
}

void	ft_print_mapy(t_map *mapy)
{
	int i;

	i = 0;
	while (i < mapy->size)
	{
		ft_putstr(mapy->arr[i]);
		ft_putchar('\n');
		i++;
	}
}

void	ft_place_piece(t_tetr *tetr, t_map *mapy, t_coord *coord, char c)
{
	int i;
	int j;

	i = 0;
	while (i < tetr->w)
	{
		j = 0;
		while (j < tetr->h)
		{
			if (tetr->pos[j][i] == '#')
				mapy->arr[coord->y + j][coord->x + i] = c;
			j++;
		}
		i++;
	}
	ft_memdel((void **)&coord);
}

int		ft_placement(t_tetr *tetr, t_map *mapy, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < tetr->w)
	{
		j = 0;
		while (j < tetr->h)
		{
			if (tetr->pos[j][i] == '#' && mapy->arr[y + j][x + i] != '.')
				return (0);
			j++;
		}
		i++;
	}
	ft_place_piece(tetr, mapy, ft_new_coord(x, y), tetr->val);
	return (1);
}
