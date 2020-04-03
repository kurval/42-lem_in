# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/05 11:23:46 by vkurkela          #+#    #+#              #
#    Updated: 2020/04/03 12:20:12 by vkurkela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC = ./sources/main.c ./sources/parse_map.c  \
	./sources/check_rooms.c ./sources/check_links.c \
	./sources/map_validation.c ./sources/shortest_path.c \
	./sources/helper_functions.c ./sources/move_ants.c
	
OBJ = $(SRC:.c=.o)
HEADERS = lem_in.h
LIBFT = libft/libft.a
LIB = lib_lem_in/lib.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
GREEN = \033[1;32m
EOC = \033[1;0m

all: $(NAME)

%.o:%.c
	$(CC) $(FLAGS) -I$(HEADERS) -o $@ -c $<

$(LIBFT):
	@${MAKE} -C libft

$(LIB):
	@${MAKE} -C lib_lem_in

$(NAME): $(OBJ) $(LIBFT) $(LIB)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(LIB)
	@echo "$(GREEN)Lem-in build completed$(EOC)"

clean:
	/bin/rm -f $(OBJ)
	@${MAKE} -C libft clean
	@${MAKE} -C lib_lem_in clean

fclean: clean
	/bin/rm -f $(NAME)
	@${MAKE} -C libft fclean
	@${MAKE} -C lib_lem_in fclean

re: fclean all

.PHONY: all clean fclean re