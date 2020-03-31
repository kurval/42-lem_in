/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 10:50:09 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/31 16:36:28 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void move(t_lem_in *anthill, t_room *tmp, t_path *path)
{
	int	nbr;

	nbr = path->nb;
	if (path->nb >= 5)
		nbr = path->nb % 5;
	nbr == 0 ? MOVE0(tmp->ant_here->name, tmp->name) : 0;
	nbr == 1 ? MOVE1(tmp->ant_here->name, tmp->name) : 0;
	nbr == 2 ? MOVE2(tmp->ant_here->name, tmp->name) : 0;
	nbr == 3 ? MOVE3(tmp->ant_here->name, tmp->name) : 0;
	nbr == 4 ? MOVE4(tmp->ant_here->name, tmp->name) : 0;
	if (tmp == anthill->end)
		anthill->finish++;
}

static void send_ants(t_lem_in *anthill, t_room *tmp, t_path *path)
{
	tmp = anthill->end;
	while (tmp)
	{
		if (tmp->prev && tmp->prev->ant_here && !tmp->ant_here) //next room is empty
		{
			tmp->ant_here = tmp->prev->ant_here; //swithches ant from previous room to point current room
			move(anthill, tmp, path); //print this move
		}
		else if (tmp->ant_here) //move next ant at the current room
		{
			if (!tmp->prev && tmp != anthill->start)
				tmp->ant_here = NULL;
			else if (tmp->prev)
				tmp->ant_here = tmp->prev->ant_here;
			else
				tmp->ant_here = tmp->ant_here->next;
			if (tmp != anthill->start && tmp->ant_here) //if current is not start AND there is ants left
				move(anthill, tmp, path);
		}
		tmp = tmp->prev;
	}
}

static void	other_path(t_lem_in *anthill, t_room *tmp, t_path *path)
{
	t_room *other_room;

	tmp = anthill->start;
	if (!tmp->ant_here)
		return ;
	other_room = path->route->room;
	other_room->ant_here = tmp->ant_here;
	tmp->ant_here = tmp->ant_here->next;
	move(anthill, other_room, path);
}

void	move_ants(t_lem_in *anthill)
{
	t_room	*tmp;
	t_path	*current_path;

    tmp = NULL;
    anthill->start->ant_here = anthill->ant_lst;
    while (anthill->finish != anthill->ants)
	{
		current_path = anthill->paths;
		while (current_path && anthill->finish != anthill->ants)
		{
			anthill->end->prev = current_path->second_last;
			send_ants(anthill, tmp, current_path);
			if (anthill->start->ant_here && current_path != anthill->paths)
			{
				if (current_path->len <= (((anthill->ants + 1) - anthill->start->ant_here->name) * anthill->paths->len))
					other_path(anthill, tmp, current_path);
			}
			current_path = current_path->next;
		}
		ft_printf("\n");
	}
}