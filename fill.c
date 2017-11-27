// MINE STUFF

typedef struct s_tetr
{
	char **tetr;
	char letter;
	int x;
	int y;
	struct s_tetr *next;
}				t_tetr;

/* return a new tetrimino and give him a letter  +++ */
t_tetr	*new(char **tetr, int nbr)
{
	t_tetr *ttt;

	ttt = NULL;
	ttt = (t_tetr*)malloc(sizeof(t_tetr));
	if (ttt == NULL)
		return (NULL);
	ttt->tetr = tetr;
	ttt->letter = 'A' + nbr;
	ttt->x = 0;
	ttt->y = 0;
	ttt->next = NULL;
	return (ttt);
}

/* split array to create a linked list of tetriminos +++ */
t_tetr		*create_linkedlist(char **arr)
{
	int			i;
	t_tetr	*st;
	t_tetr	*pt;

	i = 1;
	st = NULL;
	st = new(ft_strsplit(arr[0], '\n'), 0);
	pt = st;
	while (i < g_nb_tetrimino)
	{
		pt->next = new(ft_strsplit(arr[i], '\n'), i);
		pt = ptr->next;
		i++;
	}
	pt->next = NULL;
	return (st);
}


// BRO STUFF

/*
** return y min
*/

static int		get_y_min(char **tab)
{
	int x;
	int y;
	int y_min;

	x = 0;
	y = 0;
	y_min = 0;
	while (x < 4)
	{
		while (tab[x][y] != '#' && tab[x][y] != '\0' /* && tab[x][y] == '\n'*/)
			y++;
		if (y == 4)
			y_min++;
		else
			return (y_min);
		y = 0;
		x++;
	}
	return (y_min);
}

/*
** return x min
*/

static int		get_x_min(char **tab)
{
	int x;
	int y;
	int x_min;

	x = 0;
	y = 0;
	x_min = 4;
	while (x < 4)
	{
		while (tab[x][y] != '#' && tab[x][y] != '\0' /* && tab[x][y] == '\n'*/)
			y++;
		x_min = (y < x_min) ? y : x_min;
		y = 0;
		x++;
	}
	return (x_min);
}

/*
** arrange the tetriminos to remove the vacuum on the top left side of map
*/

t_tetrimino		*arrange(t_tetrimino *start)
{
	t_tetrimino *tmp;

	tmp = start;
	while (tmp)
	{
		tmp->tetrimino = arrange_left(get_x_min(tmp->tetrimino),\
				tmp->tetrimino);
		tmp->tetrimino = arrange_up(get_y_min(tmp->tetrimino), tmp->tetrimino);
		tmp = tmp->next;
	}
	return (start);
}

/* put the tetriminos at the top of the map */
static char		**arrange_up(int i_min, char **tab)
{
	int i;

	i = 0;
	while (i + i_min < 4)
	{
		tab[i] = tab[i + i_min];
		i++;
	}
	while (i < 4 && i_min > 0)
	{
		tab[i] = "....\0";
		i++;
	}
	return (tab);
}

/* put the tetriminos on the left of the map */
static char		**arrange_left(int j_min, char **tab)
{
	int tmp;
	int i;
	int j;

	tmp = 0;
	i = 0;
	j = 0;
	while (i < 4)
	{
		while (tab[i][j + j_min] != '\0')
		{
			tab[i][j] = tab[i][j + j_min];
			j++;
		}
		tmp = j_min;
		while (tmp > 0 && tmp > 0)
		{
			tab[i][4 - tmp] = '.';
			tmp--;
		}
		j = 0;
		i++;
	}
	return (tab);
}