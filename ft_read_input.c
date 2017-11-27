/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 15:58:38 by mbortnic          #+#    #+#             */
/*   Updated: 2017/11/24 15:58:41 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "fillit.h"

/* get the tetriino number, check tetriminos format and put the to your arr */
char	**ft_read_input(char *str)
{
	int fd;
	int bytes;
	char buffer[BUFF + 1];
	int nbr;
	char **arr;

	if ((fd = open(str, O_RDONLY)) == -1)
		return (0);
	while ((bytes = read(fd, buffer, BUFF)) != 0)
		buffer[bytes] = '\0';
	nbr = ft_tetr_numbr(buffer);
	if (!(arr = (char **)malloc(sizeof(char *) * ft_tetr_numbr(buffer) + 1)))
		return (NULL);
	if (ft_right_format(buffer) == 0)
	{
		return (NULL);
	}
	arr = ft_put_tetr(arr, buffer);
	return (arr);
}
