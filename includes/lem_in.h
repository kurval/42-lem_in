/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 11:32:55 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/11 18:52:29 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# define ROOMS 1
# define START 2
# define END 3
# define LINKS 4

typedef struct	s_lem_in
{
	long				ants;
	unsigned int		room_count;
	struct s_room		*room;
	struct s_link		*link;
    struct s_room		*start;
	struct s_room		*end;
}				t_lem_in;

typedef struct	s_room
{
	char				*name;
	int     			x;
	int					y;
	struct s_room		*next;
	int                 ant_here;
}				t_room;

typedef struct	s_link
{
	char				*from;
	char				*to;
	struct s_link		*next;
}				t_link;

typedef struct	s_hashtable
{
	unsigned int		key;
    struct s_room		*current;
	struct s_room		*connect;
}               t_hashtable;

# include "../libft/libft.h"

int     main(int arg, char **argc);
int     parse_map(t_lem_in *ant_hill);
int     add_room(t_room **root, char *name, int x_c, int y_c);
t_room	*new_node(char *data, int x_c, int y_c);
void	print_rooms(t_room *root);
void	check_start_end(t_lem_in *ant_hill, char *line, int *nbr);
int		is_empty(t_room *root);
void	free_rooms(t_room *root);
void    check_rooms(t_lem_in **ant_hill, char *line, int *nbr);
void    check_links(t_lem_in **ant_hill, char *line);
void	free_tab(char **tab);
void	free_links(t_link *root);
int		add_link(t_link **root, char *from, char *to);
void	print_links(t_link *root);
#endif