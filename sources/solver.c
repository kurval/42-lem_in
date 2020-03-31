/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 12:29:54 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/31 11:50:39 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** Links previous node to end of the shortest path.
*/

static int		link_to_end(t_lem_in *anthill, t_room **tmp, t_path	*path)
{
	if (!(add_connection(&path->route, anthill->end)))
    	print_error(anthill, 7);
	anthill->reverse_path = *tmp;
	anthill->end->prev = *tmp;
	path->second_last = *tmp;
	(*tmp)->checked = PATH;
	if (!(add_connection(&path->route, *tmp)))
    	print_error(anthill, 7);
	return (1);
}

/*
** Links shortest path back to start.
*/

static void		link_path(t_lem_in *anthill, t_room **array, t_path *path)
{
	t_room			**tmp;
	t_connect       *route;

	tmp = array;
	while (*tmp)
	{
		route = (*tmp)->connections;
		while (route)
		{
			if (route->room == anthill->reverse_path)
			{
				anthill->reverse_path->prev = *tmp;
				anthill->reverse_path = *tmp;
				if (!(add_connection(&path->route, *tmp)))
					print_error(anthill, 7);
				(*tmp)->checked = PATH;
			}
			route = route->next;
		}
		tmp++;
	}
}

static int		is_link_valid(t_lem_in *anthill, t_room **array,
t_path *path)
{
	int ret;
	t_room **new;

	ret = 0;
	new = NULL;
	if (!(new = connect_array(array, anthill->nodes)))
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

int			find_path(t_lem_in *anthill, t_room **array, t_path *path)
{
	t_room			**tmp;
	t_connect       *route;

	tmp = array;
	anthill->nodes = 0;
	while (*tmp)
	{
		(*tmp)->checked = VISITED;
		route = (*tmp)->connections;
		while (route)
		{
			anthill->nodes += 1;
			if (route->room == anthill->end && *tmp != anthill->start)
				return (link_to_end(anthill, tmp, path));
			route = route->next;
		}
		tmp++;
	}
	if (!(is_link_valid(anthill, array, path)))
		return (0);
	link_path(anthill, array, path);
	return (1);
}

/*
** Creates an array of rooms which is used to check
** each level of rooms untill it finds end or
** no paths are found. Check_short check if the start 
** and end is linked with only single link.
*/

int			solver(t_lem_in *anthill)
{
	t_room			**array;
	t_path			*new_path;

    new_path = add_path(&anthill->paths);
	array = (t_room **)malloc(sizeof(t_room*) * 2);
	if (!new_path || !array)
        print_error(anthill, 7);
	new_path->nb = anthill->nb_paths++;
	array[0] = anthill->start;
	array[1] = NULL;
	check_short(anthill);
	if (!(find_path(anthill, array, new_path)))
    {
		free(array);
		del_last(&anthill->paths);
        return (0);
	}
	reset_checked_rooms(anthill);
	if (new_path->nb != 1)
		    del_start(&new_path);
	free(array);
	return (1);
}