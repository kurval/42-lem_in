/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortest_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 12:29:54 by vkurkela          #+#    #+#             */
/*   Updated: 2020/04/09 18:20:40 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
 ** Links previous node to end of the shortest path.
*/

static int		link_to_end(t_lem_in *anthill, t_room **tmp, t_path *path)
{
	if (!(add_connect(&path->route, anthill->end)))
		print_error(anthill, 7);
	anthill->reverse_path = *tmp;
	anthill->end->prev = *tmp;
	path->second_last = *tmp;
	update_flow(anthill, (*tmp)->id, anthill->end->id);
	(*tmp)->checked = PATH;
	if (!(add_connect(&path->route, *tmp)))
		print_error(anthill, 7);
	return (1);
}

/*
 ** Links shortest path back to start.
*/

static void		link_path(t_lem_in *anthill, t_connect *queue, t_path *path)
{
	t_connect	*tmp;
	t_connect	*route;

	tmp = queue;
	while (path->route->room != anthill->start)
	{
		route = tmp->room->connections;
		while (route)
		{
			if (route->room == anthill->reverse_path &&\
			is_edge_valid(anthill, tmp->room->id, route->room->id) &&\
			tmp->room->checked != PATH)
			{
				update_flow(anthill, tmp->room->id, route->room->id);
				anthill->reverse_path->prev = tmp->room;
				anthill->reverse_path = tmp->room;
				(!(add_connect(&path->route, tmp->room))) ?\
				print_error(anthill, 7) : 0;
				tmp->room->checked = PATH;
			}
			route = route->next;
		}
		tmp = (tmp->next) ? tmp->next : queue;
	}
}

static int		is_link_valid(t_lem_in *anthill, t_room **array, t_path *path)
{
	int		ret;
	t_room	**new;

	ret = 0;
	new = NULL;
	if (!(new = connect_array(array, anthill->nodes, anthill)))
	{
		free(new);
		print_error(anthill, 7);
	}
	if (!anthill->nodes || !(find_path(anthill, new, path)))
		ret = 0;
	else
		ret = 1;
	free(new);
	return (ret);
}

/*
 ** Checks each connections of every room untill
 ** end is reached or function fails to find path.
*/

int				find_path(t_lem_in *anthill, t_room **array, t_path *path)
{
	t_room		**tmp;
	t_connect	*route;

	tmp = array;
	anthill->nodes = 0;
	while (*tmp)
	{
		(*tmp)->checked = VISITED;
		route = (*tmp)->connections;
		while (route)
		{
			anthill->nodes += 1;
			if (route->room == anthill->end && *tmp != anthill->start &&\
			is_edge_valid(anthill, (*tmp)->id, anthill->end->id))
				return (link_to_end(anthill, tmp, path));
			route = route->next;
		}
		(!(add_connect(&anthill->que, (*tmp)))) ?\
		print_error(anthill, 7) : 0;
		tmp++;
	}
	if (!(is_link_valid(anthill, array, path)))
		return (0);
	return (1);
}

int				shortest_path(t_lem_in *anthill)
{
	t_room			**array;
	t_path			*new_path;

	anthill->que = NULL;
	new_path = add_path(&anthill->paths);
	array = (t_room **)malloc(sizeof(t_room*) * 2);
	(!new_path || !array) ? print_error(anthill, 7) : 0;
	new_path->nb = anthill->nb_paths++;
	array[0] = anthill->start;
	array[1] = NULL;
	if (!check_start_flow(anthill) || !find_path(anthill, array, new_path))
	{
		reset_checked_rooms(anthill);
		free(array);
		del_last(&anthill->paths);
		return (0);
	}
	link_path(anthill, anthill->que, new_path);
	reset_checked_rooms(anthill);
	new_path->len = path_len(new_path);
	(new_path->nb != 1) ? del_start(&new_path) : 0;
	free(array);
	return (1);
}
