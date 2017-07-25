# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/25 11:05:36 by gschaetz          #+#    #+#              #
#    Updated: 2017/07/25 15:33:53 by gschaetz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

LIBFT = libft/libft.a

FLAG = -Wextra -Werror -Wall

INC = include/lem_in.h

SRC = src/main.c\
	  src/free.c\
	  src/checker.c\
	  src/calculate_constant.c\
	  src/ft_line_isdigit.c\
	  src/room.c\
	  src/is.c \
	  src/tube.c \
	  src/last_check.c

all: $(NAME)

$(NAME): $(LIBFT) $(SRC)
	gcc -o $(NAME) $(FLAG) $(SRC) -Llibft -lftprintf

$(LIBFT):
	make -C libft

clean:
	make -C libft clean

fclean: clean
	make -C libft fclean
	rm $(NAME)

re: fclean all
	
.PHONY: all fclean re clean
