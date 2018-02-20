/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetrcreation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 18:05:33 by mrybak            #+#    #+#             */
/*   Updated: 2017/12/01 18:46:08 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_coord	*ft_new_coord(int x, int y)
{
	t_coord		*coord;

	coord = ft_memalloc(sizeof(t_coord));
	coord->x = x;
	coord->y = y;
	return (coord);
}

t_tetr	*ft_tetr_struct(char **pos, int w, int h, char val)
{
	t_tetr		*tetr;

	tetr = ft_memalloc(sizeof(t_tetr));
	tetr->pos = pos;
	tetr->w = w;
	tetr->h = h;
	tetr->val = val;
	return (tetr);
}

t_tetr	*ft_get_piece(char *s, char val)
{
	t_coord		*min;
	t_coord		*max;
	char		**position;
	int			i;
	t_tetr		*tetr;

	min = ft_new_coord(3, 3);
	max = ft_new_coord(0, 0);
	ft_minmax_val(s, min, max);
	position = ft_memalloc(sizeof(char *) * (max->y - min->y + 1));
	i = 0;
	while (i < max->y - min->y + 1)
	{
		position[i] = ft_strnew(max->x - min->x + 1);
		ft_strncpy(position[i], s + (min->x) +
			(i + min->y) * 5, max->x - min->x + 1);
		i++;
	}
	tetr = ft_tetr_struct(position, max->x - min->x + 1,
		max->y - min->y + 1, val);
	ft_memdel((void **)&min);
	ft_memdel((void **)&max);
	return (tetr);
}

t_list	*ft_read_input(int fd)
{
	char	*buffer;
	int		bytes;
	t_list	*llist;
	t_tetr	*tetr;
	char	letter;

	buffer = ft_strnew(21);
	llist = NULL;
	letter = 'A';
	while ((bytes = read(fd, buffer, 21)) >= 19)
	{
		if (ft_check_valid(buffer) != 0
				|| (tetr = ft_get_piece(buffer, letter++)) == NULL)
		{
			ft_memdel((void **)&buffer);
			return (ft_free_tetr_list(llist));
		}
		ft_lstadd(&llist, ft_lstnew(tetr, sizeof(t_tetr)));
		ft_memdel((void **)&tetr);
	}
	ft_memdel((void **)&buffer);
	if (bytes != 0)
		return (ft_free_tetr_list(llist));
	ft_lstrev(&llist);
	return (llist);
}
