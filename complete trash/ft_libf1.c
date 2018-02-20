/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:12:22 by mbortnic          #+#    #+#             */
/*   Updated: 2017/11/27 14:17:12 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*arr;
	size_t	i;

	arr = b;
	i = 0;
	while (i < len)
		arr[i++] = (unsigned char)c;
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	if (n > 0)
		ft_memset(s, 0, n);
}

void	ft_strdel(char **as)
{
	if (as && *as)
	{
		free(*as);
		*as = NULL;
	}
}

void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*arr;

	if (size > 0)
	{
		i = 0;
		arr = (char *)malloc(sizeof(char) * size);
		if (arr != NULL)
		{
			while (size > 0)
			{
				arr[i] = 0;
				size--;
				i++;
			}
			return (arr);
		}
		return (NULL);
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
