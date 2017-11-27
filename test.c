/*#include "fillit.h"
#include <stdio.h>
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

int		*ft_narray(char **str)
{
	size_t	i;
	size_t	j;
	size_t	k;
	int		*array;

	array = (int*)malloc(4 * 104);
	k = 0;
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i][j] == '#')
			array[k++] = (((i % 4) + 1) * 10 + (j + 1));
		if (j == 3)
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (array);
}

int		main(int argc, char **argv)
{
	char	**clone;
	int		**xyN;

	if (argc == 2)
	{
		clone = ft_argvcopy(argv[1]);
		printf("%s\n", clone[1]);
		xyN = ft_narray(clone);
		printf("%d\n", xyN[7]);
		printf("%d\n", ft_checker(xyN));
	}
	return (0);
}*/

int			main(int argc, char **argv)
{
	t_tetrimino *start;
	char		**tab;

	start = NULL;
	tab = NULL;
	if (argc != 2)
	{
		ft_usage();
		return (-1);
	}
	if ((tab = read_stdin(argv[1])) == NULL)
	{
		ft_putendl("error");
		return (-1);
	}
	if (check(tab) == 0)
	{
		ft_putendl("error");
		free_tab(tab, g_nb_tetrimino + 1);
		return (-1);
	}
	start = splittab(tab);
	free_tab(tab, g_nb_tetrimino + 1);
	puttab(solve(start, get_square_size(), NULL));
	return (0);
}









