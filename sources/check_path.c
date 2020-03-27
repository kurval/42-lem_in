/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 12:29:54 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/27 10:47:30 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** Links previous node to end of the shortest path.
*/

static int		link_to_end(t_lem_in *anthill, t_room **tmp, t_path	*path)
{
	if (!(add_connection(&path->route, anthill->end)))
    {
        anthill->errnbr = 7;
        print_error(anthill);
    }
	anthill->reverse_path = *tmp;
	(*tmp)->checked = 2;
	if (!(add_connection(&path->route, *tmp)))
    {
        anthill->errnbr = 7;
        print_error(anthill);
    }
	return (1);
}

/*
** Links shortest path back to start.
*/

static void		link_path(t_lem_in *anthill, t_room **array, t_room **new, t_path *path)
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
				anthill->reverse_path = *tmp;
				if (!(add_connection(&path->route, *tmp)))
				{
        			anthill->errnbr = 7;
        			print_error(anthill);
   				}
				(*tmp)->checked = 2;
			}
			route = route->next;
		}
		tmp++;
	}
	free(new);
}

/*
** Creates an array of next level connections.
*/

static t_room	**connect_array(t_room **array, int rooms)
{
	t_room			**tmp;
	t_room			**new;
	t_connect       *route;
	int				i;

	i = 0;
	if (!(new = (t_room **)malloc(sizeof(t_room*) * (rooms + 1))))
		return (NULL);
	tmp = array;
	while (*tmp)
	{
		route = (*tmp)->connections;
		while (route)
		{
			if (!route->room->checked)
				new[i++] = route->room;
			route = route->next;
		}
		tmp++;
	}
	new[i] = NULL;
	return (new);
}

/*
** Checks each connections of every room untill
** end is reached or function fails to find path.
*/

static int		find_path(t_lem_in *anthill, t_room **array,
t_room **new, int rooms, t_path	*path)
{
	t_room			**tmp;
	t_connect       *route;

	tmp = array;
	while (*tmp)
	{
		(*tmp)->checked = 1;
		route = (*tmp)->connections;
		while (route)
		{
			rooms++;
			if (route->room == anthill->end && *tmp != anthill->start)
				return (link_to_end(anthill, tmp, path));
			route = route->next;
		}
		tmp++;
	}
	if (!rooms || !(new = (connect_array(array, rooms)))
	|| !(find_path(anthill, new, NULL, 0, path)))
	{
		free(new);
		return (0);
	}
	link_path(anthill, array, new, path);
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
	if (!(array = (t_room **)malloc(sizeof(t_room*) * 2)))
	{
        anthill->errnbr = 7;
        print_error(anthill);
    }
	array[0] = anthill->start;
	array[1] = NULL;
	check_short(anthill);
	if (!(find_path(anthill, array, NULL, 0, new_path)))
    {
		free(array);
        return (0);
	}
	reset_checked_rooms(anthill);
	free(array);
	return (1);
}