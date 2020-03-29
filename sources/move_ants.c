/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 10:50:09 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/29 19:34:26 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void move(t_lem_in *anthill, t_room *tmp)
{
	MOVE(tmp->ant_here->name, tmp->name);
	if (tmp == anthill->end)
		anthill->finish++;
}

static void send_ants(t_lem_in *anthill, t_room *tmp)
{
	tmp = anthill->end;
	while (tmp)
	{
		if (tmp->prev && tmp->prev->ant_here && !tmp->ant_here) //no ants at current room and ants at prev
		{
			tmp->ant_here = tmp->prev->ant_here; //swithches ant from previous room to point current room
			move(anthill, tmp); //print this move
		}
		else if (tmp->ant_here) //ant at the current room or (previous room)
		{
			tmp->ant_here = tmp->ant_here->next; //switches ant to next ant (L1 -> L2)
			if (tmp != anthill->start && tmp->ant_here) //if current is not start AND there is ants left
				move(anthill, tmp);
		}
		tmp = tmp->prev;
	}
	ft_printf("\n");
}

void	move_ants(t_lem_in *anthill)
{
	t_room	*tmp;
	t_path	*shortest_path;

    tmp = NULL;
    anthill->start->ant_here = anthill->ant_lst;
    while (anthill->finish != anthill->ants)
	{
		shortest_path = anthill->paths;
		anthill->end->prev = shortest_path->next->second_last;
		while (shortest_path && anthill->finish != anthill->ants)
		{
			send_ants(anthill, tmp); //one move
			shortest_path = shortest_path->next;
		}
	}
}