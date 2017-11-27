/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_tert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 11:42:12 by mbortnic          #+#    #+#             */
/*   Updated: 2017/11/23 18:52:28 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
