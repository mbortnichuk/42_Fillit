# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/20 11:46:30 by mbortnic          #+#    #+#              #
#    Updated: 2017/11/27 11:41:29 by mbortnic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CFLAGS = -c -Wall -Wextra -Werror -I.

HEADER = fillit.h

SRC = main.c \
	  ft_putstr.c \
	  ft_putchar.c \
	  ft_tetr_numbr.c \
	  ft_get_height.c \
	  ft_get_width.c \
	  ft_has_neighbour.c
	#ft_dma_for_map.c \
	  ft_memalloc.c \
	  ft_alone_in_map.c \
	  ft_height_tetr.c \
	  ft_width_tetr.c \
	  ft_read_file.c \
	  ft_setting_up.c \
	  ft_strsplit.c \
	  ft_tetr_numbr.c \
	  ft_validation.c \
	  ft_putstr.c \
	  ft_strsub.c \
	  ft_strsplit.c \
	  ft_right_format.c #

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) -I.
	@ echo "\033[32;1mfillit ready to go\033[0m"

%.o: %.c
	gcc $(CFLAGS) -o $@ $<

clean:
	@ rm -f *.o
	@ echo "\033[33;1mobj files are removed\033[0m"

fclean: clean
	@ rm -f $(NAME)
	@ echo "\033[31;1m$(NAME) is deleted\033[0m"

re: fclean all
	@ echo "\033[36;1mre is performed\033[0m"

norm:
	@ echo "\033[35;1mstarting looking for norme errors...\033[0m"
	norminette *.c *.h
	@ echo "\033[35;1mnorminette check finished\033[0m"

.PHONY: all clean fclean re norm
