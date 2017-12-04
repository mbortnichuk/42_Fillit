/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 18:00:56 by mrybak            #+#    #+#             */
/*   Updated: 2017/12/01 18:45:06 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_hash_connection(char *s)
{
	int sq;
	int i;

	sq = 0;
	i = 0;
	while (i < 20)
	{
		if (s[i] == '#')
		{
			if ((i + 1) < 20 && s[i + 1] == '#')
				sq++;
			if ((i - 1) >= 0 && s[i - 1] == '#')
				sq++;
			if ((i + 5) < 20 && s[i + 5] == '#')
				sq++;
			if ((i - 5) >= 0 && s[i - 5] == '#')
				sq++;
		}
		i++;
	}
	return (sq == 6 || sq == 8);
}

int		ft_check_valid(char *s)
{
	int i;
	int sq;

	sq = 0;
	i = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (!(s[i] == '#' || s[i] == '.'))
				return (1);
			if (s[i] == '#' && ++sq > 4)
				return (2);
		}
		else if (s[i] != '\n')
		{
			return (3);
		}
		i++;
	}
	if (!ft_hash_connection(s))
		return (5);
	return (0);
}

void	ft_minmax_val(char *s, t_coord *min, t_coord *max)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if (s[i] == '#')
		{
			if (i / 5 < min->y)
				min->y = i / 5;
			if (i / 5 > max->y)
				max->y = i / 5;
			if (i % 5 < min->x)
				min->x = i % 5;
			if (i % 5 > max->x)
				max->x = i % 5;
		}
		i++;
	}
}
