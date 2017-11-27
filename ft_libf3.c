/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libf3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:23:40 by mbortnic          #+#    #+#             */
/*   Updated: 2017/11/27 14:23:53 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(const char *str)
{
	size_t i;

	i = 0;
	if (str)
	{
		while (str[i] != '\0')
			ft_putchar(str[i++]);
	}
}

int		ft_sqrt(int nb)
{
	int		i;

	i = 1;
	if (nb <= 0)
		return (0);
	while (i < 46342)
	{
		if ((i * i) == nb)
			return (1);
		i++;
	}
	return (0);
}
