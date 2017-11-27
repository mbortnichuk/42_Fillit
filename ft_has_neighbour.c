/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_has_neighbour.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 11:34:30 by mbortnic          #+#    #+#             */
/*   Updated: 2017/11/22 16:24:37 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* check that hash have at least one neighbour */
int		ft_has_neighbour(char *s)
{
	int i;
	int ok;

	i = 0;
	ok = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '#')
		{
			if (s[i + 1] == '#' || s[i - 1] == '#' || s[i + 5] == '#' || \
					s[i - 5] == '#')
				ok++;
			if (ok == 4)
				return (1);
		}
		i++;
	}
	return (0);
}
