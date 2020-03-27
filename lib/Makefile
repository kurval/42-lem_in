# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/18 20:35:59 by vkurkela          #+#    #+#              #
#    Updated: 2020/03/27 13:42:57 by vkurkela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lib.a

SRC = add_ants.c add_to_map.c free_all.c \
	add_hash_table.c add_links.c helper_functions.c \
	add_rooms.c print_error.c add_paths.c\
	add_connections.c free_hashtable.c free_paths.c

HEADERS = lib.h

OBJECTS = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -I$(HEADERS)

CC = gcc

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJECTS)

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re