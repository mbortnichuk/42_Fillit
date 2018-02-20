/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:32:47 by mbortnic          #+#    #+#             */
/*   Updated: 2017/11/24 10:40:51 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "fillit.h"

int			main(int argc, char **argv)
{
	t_tetr *start;
	char		**tab;

	start = NULL;
	tab = NULL;
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit [testfile]\n");
		return (-1);
	}
	if ((tab = ft_read_input(argv[1])) == NULL)
	{
		ft_putstr("error\n");
		return (-1);
	}
	if (ft_checker(tab) == 0)
	{
		ft_putstr("error\n");
		//free_tab(tab, ntet + 1);
		return (-1);
	}
	start = ft_create_linkedlist(tab);
	//free_tab(tab, ntet + 1);
	//puttab(solve(start, get_square_size(), NULL));
	return (0);
}


	// for (int i = 0; i < 25; i++)
	// 	printf("%c\n", start->letter);