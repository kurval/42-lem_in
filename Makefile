# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/05 11:23:46 by vkurkela          #+#    #+#              #
#    Updated: 2020/03/11 13:03:31 by vkurkela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC = ./sources/main.c ./sources/parse_map.c ./sources/add_rooms.c

OBJ = $(SRC:.c=.o)

HEADERS = lem_in.h

LIBFT = libft/libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o:%.c
	$(CC) $(FLAGS) -I$(HEADERS) -o $@ -c $<

$(LIBFT):
	@${MAKE} -C libft

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT)
	mkdir -p obj
	mv $(OBJ) ./obj

clean:
	/bin/rm -f $(OBJ)
	/bin/rm -Rf obj
	@${MAKE} -C libft clean

fclean: clean
	/bin/rm -f $(NAME)
	@${MAKE} -C libft fclean

re: fclean all

.PHONY: all clean fclean re