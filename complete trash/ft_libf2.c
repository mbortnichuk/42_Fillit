/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libf2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:21:48 by mbortnic          #+#    #+#             */
/*   Updated: 2017/11/27 14:22:25 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*string;
	unsigned int	i;

	if (s != NULL)
	{
		string = (char *)malloc(sizeof(char) * len + 1);
		if (string != NULL)
		{
			i = 0;
			while (i < len)
				string[i++] = s[start++];
			string[i] = '\0';
			return (string);
		}
	}
	return (0);
}

static int		ft_wordcounter(char const *s, char c)
{
	size_t	counter;
	size_t	i;

	i = 0;
	counter = 0;
	while (i < ft_strlen(s))
	{
		if (i == 0 && s[i] != c)
			counter++;
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			counter++;
		i++;
	}
	return (counter);
}

static char		**ft_filling(char const *s, char c, char **tab)
{
	size_t		i;
	size_t		start;
	size_t		index;

	index = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			tab[index] = ft_strsub(s, start, i - start);
			index++;
			tab[index] = NULL;
		}
	}
	tab[index] = 0;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;

	if (s == NULL)
		return (NULL);
	if (!(tab = (char**)malloc(sizeof(char*) * (ft_wordcounter(s, c) + 1))))
		return (NULL);
	ft_bzero(tab, (ft_wordcounter(s, c) + 1));
	return (ft_filling(s, c, tab));
}
