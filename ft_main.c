/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 12:50:04 by mbortnic          #+#    #+#             */
/*   Updated: 2017/11/29 12:50:06 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		size_file(char *s)
{
	size_t		fd;
	size_t		len;
	char		*buf;

	fd = open(s, O_RDONLY);
	len = 0;
	if (read(fd, &buf, 1) == -1)
	{
		ft_putstr("error\n");
		exit(1);
	}
	while (read(fd, &buf, 1))
		len++;
	close(fd);
	if ((len + 2) % 21 != 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	if (len >= 546)
	{
		ft_putstr("error\n");
		return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_list	*llist;
	t_map	*mapy;
	int		k;

	k = 0;
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit [testfile]\n");
		return (1);
	}
	if ((size_file(argv[1])) == 0)
		return (0);
	close(k);
	k = open(argv[1], O_RDONLY);
	if ((llist = ft_read_input(k)) == NULL)
	{
		ft_putstr("error\n");
		return (1);
	}
	mapy = ft_solution(llist);
	ft_print_mapy(mapy);
	ft_free_mapy(mapy);
	ft_free_tetr_list(llist);
	return (0);
}
