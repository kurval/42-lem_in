# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/05 11:23:46 by vkurkela          #+#    #+#              #
#    Updated: 2020/04/13 16:19:27 by vkurkela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC = ./sources/main.c ./sources/parse_map.c  \
	./sources/check_rooms.c ./sources/check_links.c \
	./sources/map_validation.c ./sources/shortest_path.c \
	./sources/helper_functions.c ./sources/move_ants.c \
	./sources/flows.c ./sources/check_short.c \
	./sources/bfs.c ./sources/save_path.c ./sources/path_functions.c
	
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

%.o:%.c
	@$(CC) $(FLAGS) -I$(HEADERS) -o $@ -c $<

$(LIBFT):
	@echo "$(WHT)Compiling libft...$(EOC)"
	@make -C libft
	@echo "$(GREEN)Libft done.$(EOC)"

$(LIB):
	@echo "$(WHT)Compiling lem-lib...$(EOC)"
	@make -C lib_lem_in
	@echo "$(GREEN)Lem-lib done.$(EOC)"

$(NAME): $(OBJ) $(LIBFT) $(LIB)
	@echo "$(WHT)Compiling Lem-in...$(EOC)"
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(LIB)
	@echo "$(GREEN)Lem-in build completed.$(EOC)"

clean:
	@echo "$(WHT)Removing o-files...$(EOC)"
	@/bin/rm -f $(OBJ)
	@make -C libft clean
	@make -C lib_lem_in clean
	@echo "$(GREEN)Clean done.$(EOC)"

fclean: clean
	@echo "$(WHT)Removing object- and binary -files...$(EOC)"
	@/bin/rm -f $(NAME)
	@make -C libft fclean
	@make -C lib_lem_in fclean
	@echo "$(GREEN)Fclean done.$(EOC)"

re: fclean all

.PHONY: all clean fclean re