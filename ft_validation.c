/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 17:11:38 by mbortnic          #+#    #+#             */
/*   Updated: 2017/11/27 14:30:18 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* check the number of each character */
static int		ft_checkc(char *str)
{
	int i;
	int hash;
	int dot;
	int n;

	i = 0;
	hash = 0;
	dot = 0;
	n = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			hash++;
		if (str[i] =='.')
			dot++;
		if (str[i] == '\n')
			n++;
		if(str[i] != '#' && str[i] != '.' && str[i] != '\n')
			return(0);
	}
	if (hash != 4 || dot != 12 || n != 4)
		return (0);
	return (1);
}
/* check if string contains valid characters and \n */
static int		ft_checkl(char *str)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 4;
	while (str[i] != '\0')
	{
		if (str[i] == '#' || str[i] == '.')
			j++;
		if (j > 4)
			return (0);
		if (str[i] == '\n' && i == k)
		{
			j = 0;
			k += 5;
		}
		i++;
	}
	return (1);
}

/* check the shape of tetriminos */
static int		ft_checkform(char *str)
{
	int h;
	int w;
	
	h = ft_get_height(str);
	w = ft_get_width(str);
	if (ft_has_neighbour(str) == 0)
		return (0);
	if (h == 0 || w == 0)
		return (0);
	if (h == 2 && h == 2)
		return (1);
	else if (h == 2 && w == 3)
		return (1);
	else if (h == 3 && w == 2)
		return (1);
	else if (h == 1 && w == 4)
		return (1);
	else if (h == 4 && w == 1)
		return(1);
	else
		return (0);
}

/* check the arr of tetriminos, tetr by tetr */
int		ft_checker(char **str)
{
	int i;

	i = 0;
	if (str[0] == NULL)
		return (0);
	while (i < ntet)
	{
		 if (ft_checkc(str[i]) != 1)
			 return (0);
		 if (ft_checkl(str[i]) != 1)
			 return (0);
		 if (ft_checkform(str[i]) != 1)
			 return (0);
		 i++;
	}
	return (1);
}
