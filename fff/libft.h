/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 16:00:00 by mrybak            #+#    #+#             */
/*   Updated: 2017/11/12 19:25:24 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>

size_t				ft_strlen(const char *s);
char				**ft_strsplit(char const *s, char c);
size_t				ft_countsplitby(char *str, char c);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				**ft_argvcopy(char *argv);
int					ft_ifvalid(int *nbar);
int					*ft_narray(char **str);

#endif
