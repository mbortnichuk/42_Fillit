#include "fillit.h"

/*
** displays a solution
*/

/*static void	puttab(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
}*/

/*
** retrieves the size with float sqrt () and rounds it to the upper int
*/

static int	get_square_size(void)
{
	int		square_size;
	float	float_nb;

	float_nb = ft_sqrt((float)(ntet) * 4.0);
	square_size = (int)float_nb;
	if (square_size == float_nb)
		return (square_size);
	return (square_size);
}

/*
** free the array (from read_input)
*/

/*void		free_tab(char **tab, int tab_size)
{
	int i;

	i = 0;
	while (i < tab_size)
	{
		ft_strdel(&tab[i]);
		i++;
	}
	ft_strdel(tab);
}*/

int			main(int argc, char **argv)
{
	t_tetr *start;
	char		**tab;

	start = NULL;
	tab = NULL;
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit [testfile]\n");
		return (-1);
	}
	if ((tab = ft_read_input(argv[1])) == NULL)
	{
		ft_putstr("error\n");
		return (-1);
	}
	if (ft_checker(tab) == 0)
	{
		ft_putstr("error\n");
		//free_tab(tab, ntet + 1);
		return (-1);
	}
	start = ft_create_linkedlist(tab);
	//free_tab(tab, ntet + 1);
	//puttab(solve(start, get_square_size(), NULL));
	return (0);
}
