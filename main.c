/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:32:47 by mbortnic          #+#    #+#             */
/*   Updated: 2017/11/24 10:40:51 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "fillit.h"
#define BUFF_SIZE 546

int		main(int argc, char **argv)
{
// 	int fd;
// 	int bytes;
// 	char buf[BUFF_SIZE + 1];
// //	char **tmp;

// 	if (argc == 1)
// 	{
// 		ft_putstr("Usage: ./fillit [testfile]\n");
// 		return (0);
// 	}
// 	if (argc > 2)
// 	{
// 		ft_putstr("Too many arguments\n");
// 		return (0);
// 	}
// 	if ((fd = open(argv[1], O_RDONLY)) == -1)
// 		return (0);s
// 	while ((bytes = read(fd, buf, BUFF_SIZE)))
// 	{
// 		buf[bytes] = '\0';
// 		ft_putstr(buf);
// 	}
// 	if (ft_checker(&argv[1]) == 1)
// 	{
// 		printf("success!\n");
// 	}
// //	tmp = (char **)malloc(sizeof(char *) * ft_tetr_numbr(buf) + 1);
// 	close(fd);
	char	**clone;
	int		*xyN;

	if (argc == 2)
	{
		clone = ft_argvcopy(argv[1]);
		printf("%s\n", clone[1]);
		xyN = ft_narray(clone);
		printf("%d\n", xyN[9]);
		if (ft_checker(clone) == 1)
			printf("nice");
		else
			printf("looser");

	}
	return (0);
}
