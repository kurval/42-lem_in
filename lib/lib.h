/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 20:26:40 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/21 13:52:09 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H
# define SIZE 1000
# define BOLDRED "\033[1m\033[31m"
# define RESET "\033[0m"
# define ERROR(line, message) ft_printf(BOLDRED "ERROR Line %d: %s\n" RESET, line, message)
# define MESSAGE1 "usage: ./lem-in < [source file]"
# define MESSAGE2 "room name starts with L"
# define MESSAGE3 "room format: (room x y)"
# define MESSAGE4 "rooms coordinate is invalid"
# define MESSAGE5 "link format: (room-room)"
# define MESSAGE6 "room name doesn't exist"
# define MESSAGE7 "malloc error"
# define MESSAGE8 "ants must be a positive number"
# define MESSAGE10 "room allready exist"
# define MESSAGE11 "link allready exist"
# define MESSAGE12 "no links or empty map"
# define MESSAGE13 "start doesn't exist"
# define MESSAGE14 "end doesn't exist"
# define MESSAGE15 "link is connected to itself"
# include "../libft/libft.h"

typedef struct	s_lem_in
{
	long				ants;
	unsigned int		room_count;
	struct s_ants		*ant_lst;
	struct s_room		*room;
	struct s_link		*link;
    struct s_room		*start;
	struct s_room		*end;
	struct s_map		*map;
	struct s_hashtable	**hashtable;
	int					errnbr;
	int					p;
	int					line;
}				t_lem_in;

typedef struct	s_room
{
	char				*name;
	int     			x;
	int					y;
	int					checked;
    int                 key;
	struct s_room		*next;
	struct s_ants		*ant_here;
    struct s_connect	*connections;
}				t_room;

typedef struct	s_link
{
	char				*from;
	char				*to;
	struct s_link		*next;
}				t_link;

typedef struct	s_ants
{
	long				name;
	struct s_ants		*next;
}				t_ants;

typedef struct	s_hashtable
{
	unsigned int		key;
    struct s_room		*current;
	struct s_connect	*connect;
	struct s_hashtable	*next;
}               t_hashtable;

typedef struct	s_map
{
	char				*line;
	struct s_map		*next;
}				t_map;

typedef struct	s_connect
{
    struct s_room       *room;
	struct s_connect	*next;
}				t_connect;

int						add_room(t_room **root, char *name, int x_c, int y_c);
int						add_link(t_link **root, char *from, char *to);
int						add_ants(t_ants **root, long name);
int						add_to_map(t_map **root, char *rule);
void	                print_connections(t_connect *root);
void					print_links(t_link *root);
void					print_ants(t_ants *root);
void					print_map(t_lem_in *root);
void    				print_error(t_lem_in *anthill);
void					print_hashes(t_lem_in *anthill);
void					free_all(t_lem_in *anthill);
void					free_tab(char **tab);
void					count_rooms(t_lem_in *lem_in);
void                    create_hashtable(t_lem_in *anthill);
unsigned long			hash(char *str, int count);
void                    create_connections(t_lem_in *anthill);
void                    free_hashtable(t_lem_in *anthill);
#endif