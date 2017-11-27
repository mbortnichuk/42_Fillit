/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_tetr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 14:41:37 by mbortnic          #+#    #+#             */
/*   Updated: 2017/11/23 18:13:34 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* fill str with list of tetriminos */
char	**ft_put_tetr(char **str, char *arr)
{
	int i; //str
	int j; //arr
	int l; //str

	i = 0;
	j = 0;
	l = 0;
	while (i < ft_tetr_numbr(arr))
	{
		if (!(str = (char **)malloc(sizeof(char *)) * 20 + 1))
			return (NULL);
		while (l < 20)
			str[i][l++] = arr[j++];
		str[i][l] = '\0';
		l = 0;
		i++;
		j++;
	}
	str[i] = NULL;
	return (str);
}