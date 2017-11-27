/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 11:26:50 by mrybak            #+#    #+#             */
/*   Updated: 2017/11/21 15:57:01 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	char	**clone;
	int		*xyN;

	if (argc == 2)
	{
		clone = ft_argvcopy(argv[1]);
		printf("%s\n", clone[1]);
		xyN = ft_narray(clone);
		printf("%d\n", xyN[7]);
		printf("%d\n", ft_ifvalid(xyN));
	}
	return (0);
}
