/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetr_numbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 10:42:04 by mbortnic          #+#    #+#             */
/*   Updated: 2017/11/23 14:32:38 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* gives us a number of tetrimino */
int		ft_tetr_numbr(char *str)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && (str[i + 1] == '\n' || str[i + 1] == '\0'))
			nb++;
		i++;
	}
	return (nb);
}
