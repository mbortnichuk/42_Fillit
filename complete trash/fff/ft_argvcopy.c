/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argvcopy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 19:23:10 by mrybak            #+#    #+#             */
/*   Updated: 2017/11/23 19:36:53 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_filelen(int i)
{
	int		j;
	char	pack;

	j = 0;
	while (read(i, &pack, 1) != '\0')
	{
		j++;
	}
	return (j);
}

char	*ft_copy(int i, int len)
{
	char	pack;
	size_t	j;
	char	*str;

	str = (char*)malloc(len);
	j = 0;
	while (read(i, &pack, 1) != '\0')
	{
		str[j] = pack;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	**ft_argvcopy(char *argv)
{
	int		t;
	char	*str;
	int		len;
	char	**mino;

	t = open(argv, O_RDONLY);
	len = ft_filelen(t);
	close(t);
	t = open(argv, O_RDONLY);
	str = ft_copy(t, len);
	mino = ft_strsplit(str, '\n');
	close(t);
	return (mino);
}
