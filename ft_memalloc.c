/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mmalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 16:31:16 by mbortnic          #+#    #+#             */
/*   Updated: 2017/11/23 18:14:07 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
