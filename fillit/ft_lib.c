/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:44:23 by mbortnic          #+#    #+#             */
/*   Updated: 2017/11/29 11:44:23 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_memdel(void **ap)
{
	if (!ap || !*ap)
		return ;
	free(*ap);
	*ap = NULL;
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

char	*ft_strnew(size_t size)
{
	char *string;

	if (!(string = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_memset(string, '\0', size + 1);
	return (string);
}

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

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while ((i < len) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	while (i < len)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
