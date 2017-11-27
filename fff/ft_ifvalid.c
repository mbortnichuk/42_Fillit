/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ifvalid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 19:14:08 by mrybak            #+#    #+#             */
/*   Updated: 2017/11/23 19:14:12 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_check1to2(int *r, size_t n)
{
	if ((r[n + 1] + 10) == r[n + 2] || (r[n + 1] + 1) == r[n + 2])
	{
		if ((r[n + 2] + 1) == r[n + 3] || (r[n + 2] + 10) == r[n + 3])
			return (1);
		else if ((r[n + 1] + 10) == r[n + 3] || (r[n + 1] + 1) == r[n + 3])
			return (1);
		else if ((r[n] + 10) == r[n + 3] || (r[n] + 10) == r[n + 3])
			return (1);
	}
	if ((r[n + 1] + 10) == r[n + 3] || (r[n + 1] + 1) == r[n + 3])
	{
		if ((r[n + 3] - 10) == r[n + 2] || (r[n + 3] - 1) == r[n + 2])
			return (1);
		else if ((r[n + 1] + 10) == r[n + 2] || (r[n + 1] + 1) == r[n + 2])
			return (1);
	}
	if ((r[n] + 10) == r[n + 2] || (r[n] + 1) == r[n + 2])
		if ((r[n + 2] + 10) == r[n + 3] || (r[n + 2] + 1) == r[n + 3])
			return (1);
	if ((r[n] + 10) == r[n + 3] || (r[n] + 1) == r[n + 3])
		if ((r[n + 3] - 10) == r[n + 2] || (r[n + 3] - 1) == r[n + 2])
			return (1);
	return (0);
}

int		ft_check1to3(int *r, size_t n)
{
	if ((r[n + 2] - 10) == r[n + 1] || (r[n + 2] - 1) == r[n + 1])
	{
		if ((r[n + 2] + 10) == r[n + 3] || (r[n + 2] + 1) == r[n + 3])
			return (1);
		else if ((r[n + 1] + 10) == r[n + 3] || (r[n + 1] + 1) == r[n + 3])
			return (1);
	}
	if ((r[n + 2] + 10) == r[n + 3] || (r[n + 2] + 1) == r[n + 3])
	{
		if ((r[n + 3] - 10) == r[n + 1] || (r[n + 3] - 1) == r[n + 1])
			return (1);
		else if ((r[n + 2] - 10) == r[n + 1] || (r[n + 2] - 1) == r[n + 1])
			return (1);
	}
	return (0);
}

int		ft_check1to4(int *r, size_t n)
{
	if ((r[n + 3] - 10) == r[n + 1] || (r[n + 3] - 1) == r[n + 1])
	{
		if ((r[n + 3] - 10) == r[n + 2] || (r[n + 3] - 1) == r[n + 2])
			return (1);
		else if ((r[n + 1] + 10) == r[n + 2] || (r[n + 1] + 1) == r[n + 2])
			return (1);
	}
	if ((r[n + 3] - 10) == r[n + 2] || (r[n + 3] - 1) == r[n + 2])
	{
		if ((r[n + 3] - 10) == r[n + 1] || (r[n + 3] - 1) == r[n + 1])
			return (1);
		else if ((r[n + 2] - 10) == r[n + 1] || (r[n + 2] - 1) == r[n + 1])
			return (1);
	}
	return (0);
}

int		ft_checkit(int *r, size_t n)
{
	if ((r[n] + 10) == r[n + 1] || (r[n] + 1) == r[n + 1])
	{
		if (ft_check1to2(r, n) == 1)
			return (1);
	}
	if ((r[n] + 10) == r[n + 2] || (r[n] + 1) == r[n + 2])
	{
		if (ft_check1to3(r, n) == 1)
			return (1);
	}
	if ((r[n] + 10) == r[n + 3] || (r[n] + 1) == r[n + 3])
	{
		if (ft_check1to4(r, n) == 1)
			return (1);
	}
	return (0);
}

int		ft_ifvalid(int *nbar)
{
	size_t	i;
	size_t	j;
	size_t	ok;

	i = 0;
	j = 0;
	while (nbar[i] != 0)
	{
		ok = 0;
		if (ft_checkit(nbar, i) == 1)
			ok = 1;
		if (ok == 1)
			i = i + 4;
		else
			return (0);
	}
	return (1);
}
