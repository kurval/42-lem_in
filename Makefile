# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/05 11:23:46 by vkurkela          #+#    #+#              #
#    Updated: 2020/03/19 18:37:14 by vkurkela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC = ./sources/main.c ./sources/parse_map.c  \
	 ./sources/check_rooms.c ./sources/check_links.c \
	./sources/map_validation.c \
	

OBJ = $(SRC:.c=.o)

HEADERS = lem_in.h

LIBFT = libft/libft.a
LIB = lib/lib.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o:%.c
	$(CC) $(FLAGS) -I$(HEADERS) -o $@ -c $<

$(LIBFT):
	@${MAKE} -C libft

$(LIB):
	@${MAKE} -C lib

$(NAME): $(LIBFT) $(LIB) $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(LIB)
	mkdir -p obj
	mv $(OBJ) ./obj

clean:
	/bin/rm -f $(OBJ)
	/bin/rm -Rf obj
	@${MAKE} -C libft clean
	@${MAKE} -C lib clean

fclean: clean
	/bin/rm -f $(NAME)
	@${MAKE} -C libft fclean
	@${MAKE} -C lib fclean

re: fclean all

.PHONY: all clean fclean re