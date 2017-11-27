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

#include "fillit.h"

char	**ft_read_input(char **str)
{
	int fd;
	int bytes;
	char buffer[BUFF + 1];
	int nbr;
	char **str;

	if ((fd = open(str, O_RDOLNY)) == -1)
		return (0);
	while ((bytes = read(fd, buffer, BUFF)) != 0)
		buffer[bytes] = '\0';
	nbr = ft_tetr_numbr(buffer);
	if (!(str = (char **)malloc(sizeof(char *) * ft_tetr_numbr(buffer) + 1)))
		return (NULL);
	str = ft_put_tetr(str, buffer);
	return (str);
}