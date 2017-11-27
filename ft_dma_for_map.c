/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dma_for_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:35:41 by mbortnic          #+#    #+#             */
/*   Updated: 2017/11/23 19:24:47 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* allocate enough memory for the solution */
char	**ft_dma_for_map(char **arr, int mapsize)
{
	int i;
	int j;

	i = 0;
	j = 0;
	arr = ft_memalloc(sizeof(char *) * mapsize + 1);
	while (j < mapsize)
	{
		arr[j] = ft_memalloc(sizeof(char *) * mapsize + 1);
		j++;
	}
	while (i < mapsize)
	{
		while (j < mapsize)
		{
			arr[i][j++] = '.';
		}
		arr[i][j] = '\0';
		j = 0;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
