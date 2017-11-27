# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/20 11:46:30 by mbortnic          #+#    #+#              #
#    Updated: 2017/11/27 15:43:50 by mbortnic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CFLAGS = -c -Wall -Wextra -Werror -I.

HEADER = fillit.h

SRC = ft_dma_for_map.c ft_get_height.c ft_get_width.c ft_has_neighbour.c \
		ft_libf1.c ft_libf2.c ft_libf3.c ft_put_tetr.c ft_read_input.c \
		ft_right_format.c ft_tetr_numbr.c ft_validation.c ft_create_linkedlist.c \
		main.c

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
