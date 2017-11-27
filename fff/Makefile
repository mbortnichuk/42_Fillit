# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrybak <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/02 11:15:44 by mrybak            #+#    #+#              #
#    Updated: 2017/11/14 20:08:43 by mrybak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
HEADERS = libft.h

SRC = ft_strlen.c \
	   ft_strsplit.c \
	   ft_countsplitby.c \
	   ft_strsub.c \
	   ft_argvcopy.c \
	   ft_ifvalid.c \
	   ft_narray.c \

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	@echo "\033[36mMaster!\nYour libft.a is ready to work.\033[0m"

$(OBJ): %.o: %.c
	gcc -c $(FLAGS) $< -o $@

clean:
	rm -f $(OBJ)
	@echo "\033[36mMaster, allow me to report!\n I had destroy all this trash! (clean completed)\033[0m"

fclean: clean
	rm -f libft.a
	@echo "\033[36mMaster, allow me to report!\nEven libft is not exeption (fclean completed)\033[0m"

re: fclean all

.PHONY: all clean fclean re