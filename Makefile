# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/05 11:23:46 by vkurkela          #+#    #+#              #
#    Updated: 2020/04/07 17:53:37 by vkurkela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC = ./sources/main.c ./sources/parse_map.c  \
	./sources/check_rooms.c ./sources/check_links.c \
	./sources/map_validation.c ./sources/shortest_path.c \
	./sources/helper_functions.c ./sources/move_ants.c \
	./sources/flows.c
	
OBJ = $(SRC:.c=.o)
HEADERS = lem_in.h
LIBFT = libft/libft.a
LIB = lib_lem_in/lib.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
GREEN = \033[1;32m
RED = \033[1;31m
YEL = \033[1;33m
WHT = \033[1;37m
EOC = \033[1;0m

all: $(NAME)
	@echo "$(YEL)* * * * * * * * * * * * * * * * * * * * *$(EOC)"
	@echo "$(YEL)*  _                           _        *$(EOC)"
	@echo "$(YEL)* | |                         (_)       *$(EOC)"
	@echo "$(YEL)* | | ___ _ __ ___    ______   _ _ __   *$(EOC)"
	@echo "$(YEL)* | |/ _ \ '_ \` _ \  |______| | | '_ \  *$(EOC)"
	@echo "$(YEL)* | |  __/ | | | | |          | | | | | *$(EOC)"
	@echo "$(YEL)* |_|\___|_| |_| |_|          |_|_| |_| *$(EOC)"
	@echo "$(YEL)*                                       *$(EOC)"
	@echo "$(YEL)* * * * * * * * * * * * * * * * * * * * *$(EOC)"
	@echo "$(WHT)usage: ./lem-in [-p] < [source file]$(EOC)"

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