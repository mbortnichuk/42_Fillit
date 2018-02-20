/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_height_tetr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 11:34:43 by mbortnic          #+#    #+#             */
/*   Updated: 2017/11/23 20:09:20 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* check the height (by column) */
int		ft_get_height(char *str)
{
	int i;
	int w;
	int lines;

	i = 0;
	w = 0;
	lines = 0;
	while (i < 4)
	{
		if (str[i] == '#' || str[i + 5] == '#' || str[i + 10] == '#' || \
				str[i + 15] == '#')
		{
			w++;
			if (lines > 0)
				return (0);
		}
		else if (w > 0)
			lines++;
		i++;
	}
	return (w);
}

/* check the width (by lines) */
int		ft_get_width(char *str)
{
	int i;
	int h;
	int lines;

	i = 0;
	h = 0;
	lines = 0;
	while (i < 19)
	{
		if (str[i] == '#' || str[i + 1] == '#' || str[i + 2] == '#' ||\
				str[i + 3] == '#')
		{
			h++;
			if (lines > 0)
				return (0);
		}
		else if (h > 0)
			lines++;
		i += 5;
	}
	return (h);
}
