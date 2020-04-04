/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 10:46:37 by vkurkela          #+#    #+#             */
/*   Updated: 2020/04/03 17:38:45 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		count_connect(t_room *room)
{
	t_connect	*current;
	int			count;

	current = room->connections;
	count = 0;
	while(current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

void	init_anthill(t_lem_in *anthill)
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
}

void	check_short(t_lem_in *anthill)
{
	t_connect	*current;
	t_path		*new_path;

	new_path = NULL;
	if (anthill->quick)
		return ;
	current = anthill->start->connections;
	while (current)
	{
		if (current->room == anthill->end)
		{
			new_path = add_path(&anthill->paths);
			if (!new_path || !(add_connect(&new_path->route, anthill->end)) ||\
					!(add_connect(&new_path->route, anthill->start)))
				print_error(anthill, 7);
			anthill->quick = 1;
			new_path->second_last = anthill->start;
			new_path->nb = anthill->nb_paths++;
			return ;
		}
		current = current->next;
	}
	anthill->quick = -1;
}

/*
 ** Creates an array of next level connections.
*/

t_room	**connect_array(t_room **array, int rooms, t_lem_in *anthill)
{
	t_room		**tmp;
	t_room		**new;
	t_connect	*route;
	int			i;

	i = 0;
	if (!(new = (t_room **)malloc(sizeof(t_room*) * (rooms + 1))))
		return (NULL);
	tmp = array;
	while (*tmp)
	{
		route = (*tmp)->connections;
		while (route)
		{
			if (!route->room->checked &&\
			!(*tmp == anthill->start && route->room == anthill->end))
				new[i++] = route->room;
			route = route->next;
		}
		tmp++;
	}
	new[i] = NULL;
	return (new);
}

void	reset_checked_rooms(t_lem_in *anthill)
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

void	check_start_end(t_lem_in *anthill, char *line)
{
	if (!ft_strncmp_end(line, "##start", 7) && !anthill->start)
		anthill->section = START;
	else if (!ft_strncmp_end(line, "##end", 5) && !anthill->end)
		anthill->section = END;
}
