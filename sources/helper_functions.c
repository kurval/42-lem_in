/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 10:46:37 by vkurkela          #+#    #+#             */
/*   Updated: 2020/04/12 19:17:10 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		init_anthill(t_lem_in *anthill)
{
	anthill->ants = 0;
	anthill->room_count = 0;
	anthill->ant_lst = NULL;
	anthill->room = NULL;
	anthill->link = NULL;
	anthill->start = NULL;
	anthill->end = NULL;
	anthill->map = NULL;
	anthill->hashtable = NULL;
	anthill->paths = NULL;
	anthill->errnbr = 0;
	anthill->section = 0;
	anthill->line = 0;
	anthill->quick = 0;
	anthill->reverse_path = NULL;
	anthill->nodes = 0;
	anthill->finish = 0;
	anthill->nb_paths = 1;
	anthill->flag = 0;
	anthill->moves = 0;
	anthill->flow = NULL;
	anthill->id = 0;
	anthill->extra = 0;
}

static void	add_next_level(t_lem_in *anthill, t_room *tmp, t_room **new, int *i)
{
	t_connect	*route;

	route = tmp->connections;
	while (route)
	{
		if (is_edge_valid(anthill, tmp->id, route->room->id) &&\
		route->room != anthill->end && route->room->checked != NEG &&\
		route->room->checked != VISITED)
		{
			if (anthill->flow[tmp->id][route->room->id] == -1 &&\
			route->room->checked == PATH)
				route->room->checked = NEG;
			new[*i] = route->room;
			*i += 1;
		}
		route = route->next;
	}
}

/*
 ** Creates an array of next level connections.
*/

t_room		**connect_array(t_room **array, int rooms, t_lem_in *anthill)
{
	t_room		**tmp;
	t_room		**new;
	int			i;

	i = 0;
	if (!(new = (t_room **)malloc(sizeof(t_room*) * (rooms + 1))))
		return (NULL);
	tmp = array;
	while (*tmp)
	{
		add_next_level(anthill, *tmp, new, &i);
		tmp++;
	}
	new[i] = NULL;
	return (new);
}

void		reset_checked_rooms(t_lem_in *anthill)
{
	t_room	*current;

	current = anthill->room;
	while (current)
	{
		if (current->checked != 2)
			current->checked = 0;
		current = current->next;
	}
}

void		check_start_end(t_lem_in *anthill, char *line)
{
	if (!ft_strncmp_end(line, "##start", 7) && !anthill->start)
		anthill->section = START;
	else if (!ft_strncmp_end(line, "##end", 5) && !anthill->end)
		anthill->section = END;
}
