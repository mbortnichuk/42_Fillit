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

# define BUFF 4096
int ntet;

int				ft_has_neighbour(char *str);
int				ft_tetr_numbr(char *str);
int				ft_checker(char **str);
int				ft_get_width(char *str);
int				ft_get_height(char *str);
char			**ft_dma_for_map(char **arr, int mapsize);
void			*ft_memalloc(size_t size);
void			ft_putstr(const char *s);
void			ft_putchar(char c);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			**ft_strsplit(char const *s, char c);
int				ft_right_format(char *str);
char			**ft_argvcopy(char *argv);
int				*ft_narray(char **str);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);


typedef struct	s_tetr
{
	char	*tetr;
	int		x;
	int		y;
	char	letter;
	struct s_tetr	*next;
}				t_tetr;

#endif
