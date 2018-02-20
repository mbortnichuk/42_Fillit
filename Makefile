# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/20 11:46:30 by mbortnic          #+#    #+#              #
#    Updated: 2017/12/01 18:44:43 by mbortnic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CFLAGS = -c -Wall -Wextra -Werror -I.

HEADER = fillit.h

SRC = ft_fillit.c ft_lib.c ft_lib2.c ft_lib3.c ft_main.c ft_validation.c ft_solve.c ft_freeitall.c ft_tetrcreation.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) -I.
	@ echo "\033[32;1mfillit ready to go\033[0m"

%.o: %.c
	gcc $(CFLAGS) -o $@ $<

clean:
	@ rm -f $(OBJ)
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
