/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 11:32:55 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/27 13:42:30 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# define ROOMS 1
# define START 2
# define END 3
# define LINKS 4
# define COMMAND 5
# include "../libft/libft.h"
# include "../lib/lib.h"

int		main(int arg, char **argc);
void	init_anthill(t_lem_in *anthill);
int		parse_map(t_lem_in *anthill);
void	validate_map(t_lem_in *anthill);
void	check_start_end(t_lem_in *anthill, char *line);
void	check_rooms(t_lem_in **anthill, char *line);
void	check_links(t_lem_in **anthill, char *line);
int		is_valid_room(t_room *root, char *name);
int     solver(t_lem_in *anthill);
void	reset_checked_rooms(t_lem_in *anthill);
void	check_short(t_lem_in *anthill);
int		find_path(t_lem_in *anthill, t_room **array, t_path *path);
t_room	**connect_array(t_room **array, int rooms);
#endif