/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 11:32:55 by vkurkela          #+#    #+#             */
/*   Updated: 2020/04/15 15:27:28 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# define ROOMS 1
# define START 2
# define END 3
# define LINKS 4
# define COMMAND 5
# define VISITED 1
# define PATH 2
# define NEG -1
# define EXTRA 3
# include "../libft/libft.h"
# include "lib.h"

int		main(int arg, char **argc);
void	init_anthill(t_lem_in *anthill);
int		parse_map(t_lem_in *anthill);
void	validate_map(t_lem_in *anthill);
void	check_start_end(t_lem_in *anthill, char *line);
void	check_rooms(t_lem_in **anthill, char *line);
void	check_links(t_lem_in **anthill, char *line);
int		is_valid_room(t_room *root, char *name);
int		shortest_path(t_lem_in *anthill);
void	check_short(t_lem_in *anthill);
int		bfs(t_lem_in *anthill, t_room **array, t_path *path);
t_room	**connect_array(t_room **array, int rooms, t_lem_in *anthill);
int     move_ants(t_lem_in *anthill, t_path *path);
void	create_flow_chart(t_lem_in *anthill);
void	update_flow(t_lem_in *anthill, int id1, int id2);
int		check_start_flow(t_lem_in *anthill);
int		is_edge_valid(t_lem_in *anthill, int id1, int id2);
int     is_link_valid(t_lem_in *anthill, t_room **array, t_path *path);
void	link_path(t_lem_in *anthill, t_connect *queue, t_path *path);
int     solver(t_lem_in *anthill);
int     check_max_paths(t_lem_in *anthill);
int		link_to_end(t_lem_in *anthill, t_room **tmp, t_path *path);
#endif
