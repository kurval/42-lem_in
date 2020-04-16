/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 20:26:40 by vkurkela          #+#    #+#             */
/*   Updated: 2020/04/16 21:14:42 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H
# define SIZE 1000
# define BOLDRED		"\033[1m\033[31m"
# define BOLDCYAN		"\033[1m\033[36m"
# define WHT		"\033[1m\033[37m"
# define BOLDYELLOW		"\033[1m\033[33m"
# define BOLDBLUE		"\033[1m\033[34m"
# define BOLDMAGENTA	"\033[1m\033[35m"
# define GREEN			"\033[32m"
# define EOC			"\033[0m"
# define ERR	"(line %d): %s\n"
# define MSG1	"usage: ./lem-in [-p] < [source file]"
# define MSG2	"room name starts with L"
# define MSG3	"room format: (room x y)"
# define MSG4	"invalid coordinate (must be a positive integer)"
# define MSG5	"link format: (room-room)"
# define MSG6	"room name doesn't exist"
# define MSG7	"malloc error"
# define MSG8	"invalid ants"
# define MSG9	"no paths"
# define MSG10	"room allready exist"
# define MSG11	"link allready exist"
# define MSG12	"no links or empty map"
# define MSG13	"start doesn't exist"
# define MSG14	"end doesn't exist"
# define MSG16	"error while reading input"
# define MSG17	"room allready exist at the same location"
# include "../libft/libft.h"

typedef struct			s_lem_in
{
	long				ants;
	long				finish;
	int					errnbr;
	int					section;
	int					line;
	int					nodes;
	int					nb_paths;
	unsigned int		room_count;
	int					flag;
	int					moves;
	int					**flow;
	int					id;
	int					extra;
	int					print;
	struct s_ants		*ant_lst;
	struct s_room		*room;
	struct s_link		*link;
	struct s_room		*start;
	struct s_room		*end;
	struct s_map		*map;
	struct s_hashtable	**hashtable;
	struct s_path		*paths;
	struct s_path		*paths2;
	struct s_room		*reverse_path;
	struct s_connect	*que;
}						t_lem_in;

typedef struct			s_room
{
	char				*name;
	int					checked;
	unsigned long		key;
	int					x;
	int					y;
	int					id;
	int					second;
	struct s_room		*next;
	struct s_room		*prev;
	struct s_ants		*ant_here;
	struct s_connect	*connections;
}						t_room;

typedef struct			s_link
{
	char				*from;
	char				*to;
	struct s_link		*next;
}						t_link;

typedef struct			s_ants
{
	long				name;
	struct s_ants		*next;
}						t_ants;

typedef struct			s_hashtable
{
	unsigned long		key;
	struct s_room		*current;
	struct s_connect	*connect;
	struct s_hashtable	*next;
}						t_hashtable;

typedef struct			s_map
{
	char				*line;
	struct s_map		*next;
}						t_map;

typedef struct			s_connect
{
	struct s_room		*room;
	struct s_connect	*next;
}						t_connect;

typedef struct			s_path
{
	struct s_connect	*route;
	struct s_path		*next;
	struct s_room		*second_last;
	int					nb;
	int					len;
	int					type;
}						t_path;

int						add_room(t_lem_in **anthill, char *name,\
int x_c, int y_c);
int						add_link(t_link **root, char *from, char *to);
int						add_ants(t_ants **root, long name);
int						add_to_map(t_map **root, char *rule);
void					print_path(t_lem_in *anthill, t_path *root);
void					print_map(t_lem_in *root);
void					print_error(t_lem_in *anthill, int errnbr);
void					free_all(t_lem_in *anthill);
void					free_tab(char **tab);
void					count_rooms(t_lem_in *lem_in);
void					create_hashtable(t_lem_in *anthill);
unsigned long			hash(char *str, int count);
void					create_connections(t_lem_in *anthill);
void					free_hashtable(t_lem_in *anthill);
t_path					*add_path(t_path **root);
int						add_connect(t_connect **root, t_room *to);
void					free_paths(t_path *root);
void					free_connections(t_connect *root);
void					del_last(t_path **root);
void					del_start(t_path **root);
int						path_len(t_path *root);
void					free_flow_chart(t_lem_in *anthill);
void					print_rev_names(t_path *path);
void					del_node(t_path **node);
void					print_anthill(t_lem_in *anthill, int ret);
#endif
