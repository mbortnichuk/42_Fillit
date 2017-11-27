/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 10:36:45 by mbortnic          #+#    #+#             */
/*   Updated: 2017/11/24 12:52:49 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>

# define 		BUFF 4096
int ntet;

typedef struct s_tetr
{
	char **tetr;
	char letter;
	int x;
	int y;
	struct s_tetr *next;
}				t_tetr;

char			**ft_dma_for_map(char **arr, int mapsize);
int				ft_get_height(char *str);
int				ft_get_width(char *str);
int				ft_has_neighbour(char *s);
char			**ft_put_tetr(char **str, char *arr);
char			**ft_read_input(char *str);
int				ft_right_format(char *str);
int				ft_tetr_numbr(char *str);
int				ft_checker(char **str);
t_tetr			*ft_new(char **tetr, int nbr);
t_tetr			*ft_create_linkedlist(char **arr);

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			ft_strdel(char **as);
void			*ft_memalloc(size_t size);
size_t			ft_strlen(const char *s);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			**ft_strsplit(char const *s, char c);
void			ft_putchar(char c);
void			ft_putstr(const char *str);
int				ft_sqrt(int nb);

#endif
