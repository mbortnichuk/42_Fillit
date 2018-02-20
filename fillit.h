/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit1.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:23:38 by mbortnic          #+#    #+#             */
/*   Updated: 2017/11/29 11:23:39 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>

typedef	struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_map
{
	int			size;
	char		**arr;
}				t_map;

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_tetr
{
	char		**pos;
	int			w;
	int			h;
	char		val;
}				t_tetr;

int				ft_hash_connection(char *s);
int				ft_check_valid(char *s);
void			ft_minmax_val(char *s, t_coord *min, t_coord *max);
t_coord			*ft_new_coord(int x, int y);
t_tetr			*ft_tetr_struct(char **pos, int w, int h, char val);
void			ft_free_struct(t_tetr *tetr);
t_list			*ft_free_tetr_list(t_list *list);
t_tetr			*ft_get_piece(char *s, char val);
t_list			*ft_read_input(int fd);
t_map			*ft_create_mapy(int n);
void			ft_print_mapy(t_map *map);
void			ft_free_mapy(t_map *map);
void			ft_place_piece(t_tetr *tetr, t_map *mapy,
	t_coord *coord, char c);
int				ft_placement(t_tetr *tetr, t_map *mapy, int x, int y);
int				ft_sqrt(int n);
int				ft_solve_map(t_map *mapy, t_list *list);
t_map			*ft_solution(t_list *list);
void			ft_memdel(void **ap);
void			*ft_memalloc(size_t size);
char			*ft_strnew(size_t size);
void			*ft_memset(void *b, int c, size_t len);
char			*ft_strncpy(char *dst, const char *src, size_t len);
void			ft_lstadd(t_list **alst, t_list *new);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			ft_lstrev(t_list **alst);
size_t			ft_lstcount(t_list *lst);
void			ft_putchar(char c);
void			ft_putstr(const char *str);

#endif
