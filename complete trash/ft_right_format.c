/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_right_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:53:52 by mbortnic          #+#    #+#             */
/*   Updated: 2017/11/24 12:53:28 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* just check the correct format of the parts in the file */
int		ft_right_format(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			j++;
		if (j == 4)
		{
			if (str[i + 1] != '\n' && str[i + 1] != '\0')
				return (0);
			if (str[i + 1] == '\n')
				i++;
			j = 0;
		}
		i++;
	}
	return (1);
}
