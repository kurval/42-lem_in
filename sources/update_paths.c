/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 19:34:38 by vkurkela          #+#    #+#             */
/*   Updated: 2020/04/16 21:40:20 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		reset_checked_rooms(t_lem_in *anthill)
{
	t_room	*current;

	current = anthill->room;
	while (current)
	{
		if (current->checked != PATH)
			current->checked = 0;
		current = current->next;
	}
}

static int	check_dub(t_lem_in *anthill, t_room *room, t_path *path)
{
	if (room->checked == 4 && room != anthill->end)
	{
		path->type = NEG;
		return (0);
	}
	return (1);
}

static void	count_paths(t_lem_in *anthill)
{
	t_path	*current;

	anthill->nb_paths = 0;
	current = anthill->paths;
	while (current)
	{
		if (current->type != NEG)
			anthill->nb_paths++;
		current = current->next;
	}
}

static void	update_prev(t_lem_in *anthill, t_path *current,\
		t_connect *temp, t_connect *prev)
{
	int i;

	i = 0;
	while (temp && current->type != NEG)
	{
		if (i == 0 && prev->room->checked == 4)
		{
			current->type = NEG;
			return ;
		}
		i == 0 ? prev->room->prev = NULL : 0;
		i == 0 ? prev->room->checked = 4 : 0;
		if (check_dub(anthill, temp->room, current))
			temp->room->prev = prev->room;
		temp->room->checked = 4;
		prev = prev->next;
		temp = temp->next;
		i++;
	}
}

/*
 ** Updating rooms to point previous node.
*/

void		update_rev_paths(t_lem_in *anthill, t_path *path)
{
	t_path		*current;
	t_connect	*temp;
	t_connect	*prev;

	current = path;
	reset_checked_rooms(anthill);
	while (current)
	{
		if (current->type != NEG)
		{
			temp = current->route->next;
			prev = current->route;
			update_prev(anthill, current, temp, prev);
		}
		current = current->next;
	}
	count_paths(anthill);
}
