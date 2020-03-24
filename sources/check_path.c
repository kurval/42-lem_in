/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 12:29:54 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/24 21:04:08 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int		trace_route_back(t_lem_in *lem_in, t_room **tmp)
{
	(*tmp)->path_next = lem_in->end;
	lem_in->end->path_prev = *tmp;
	lem_in->reverse_path = *tmp;
	return (1);
}

static void		find_path(t_lem_in *lem_in, t_room **array, t_room **new)
{
	t_room			**tmp;
	t_connect       *route;

	tmp = array;
	while (*tmp)
	{
		route = (*tmp)->connections;
		while (route)
		{
			if (route->room == lem_in->reverse_path && route->room != *tmp)
			{
				(*tmp)->path_next = lem_in->reverse_path;
				lem_in->reverse_path->path_prev = *tmp;
				lem_in->reverse_path = *tmp;
			}
			route = route->next;
		}
		tmp++;
	}
	free(new);
}

static t_room	**create_mad_array(t_room **array, int rooms)
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

static int		recursive_check(t_lem_in *lem_in, t_room **array,
t_room **new, int rooms)
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
			if (route->room == lem_in->end)
				return (trace_route_back(lem_in, tmp));
			route = route->next;
		}
		tmp++;
	}
	if (!rooms || !(new = (create_mad_array(array, rooms)))
	|| !(recursive_check(lem_in, new, NULL, 0)))
	{
		free(new);
		return (0);
	}
	find_path(lem_in, array, new);
	return (1);
}

void			solve(t_lem_in *anthill)
{
	t_room			**array;

	if (!(array = (t_room **)malloc(sizeof(t_room*) * 2)))
	{
        anthill->errnbr = 7;
        print_error(anthill);
    }
	array[0] = anthill->start;
	array[1] = NULL;
	if (!(recursive_check(anthill, array, NULL, 0)))
    {
        anthill->errnbr = 9;
		free(array);
        print_error(anthill);
    }
	free(array);
}