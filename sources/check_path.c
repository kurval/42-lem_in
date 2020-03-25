/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 12:29:54 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/25 15:31:28 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	reset_checked_rooms(t_lem_in *anthill)
{
	t_room	*current;

	current = anthill->room;
	while (current)
	{
		current->checked = 0;
		current = current->next;
	}
}

static int		link_to_end(t_lem_in *lem_in, t_room **tmp)
{
	(*tmp)->path_next = lem_in->end;
	lem_in->end->path_prev = *tmp;
	lem_in->reverse_path = *tmp;
	return (1);
}

static void		link_path(t_lem_in *lem_in, t_room **array, t_room **new)
{
	t_room			**tmp;
	t_connect       *route;

	tmp = array;
	while (*tmp)
	{
		route = (*tmp)->connections;
		while (route)
		{
			if (route->room == lem_in->reverse_path)
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
				return (link_to_end(lem_in, tmp));
			route = route->next;
		}
		tmp++;
	}
	if (!rooms || !(new = (connect_array(array, rooms)))
	|| !(recursive_check(lem_in, new, NULL, 0)))
	{
		free(new);
		return (0);
	}
	link_path(lem_in, array, new);
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
	reset_checked_rooms(anthill);
	save_path(anthill);
	free(array);
}