/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 10:50:09 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/29 15:16:08 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void move(t_lem_in *anthill, t_room *tmp)
{
	while (tmp)
	{
		if (tmp->prev && tmp->prev->ant_here && !tmp->ant_here) //no ants at current room and ants at prev
		{
			tmp->ant_here = tmp->prev->ant_here; //swithches ant from previous room to point current room
			MOVE(tmp->ant_here->name, tmp->name); //print this move
		}
		else if (tmp->ant_here) //ant at the current room or (previous room)
		{
			tmp->ant_here = tmp->ant_here->next; //switches ant to next ant (L1 -> L2)
			if (tmp != anthill->start && tmp->ant_here) //if current is not start AND there is ants left
				MOVE(tmp->ant_here->name, tmp->name);
		}
		tmp = tmp->prev;
	}
		
}

void	move_ants(t_lem_in *anthill)
{
	t_room	*tmp;

    tmp = NULL;
    anthill->start->ant_here = anthill->ant_lst;
    anthill->end->prev = anthill->paths->next->second_last;
    while (1)
	{
		tmp = anthill->end; //this will only track one path at the time untill all ants get to end
		if (tmp->ant_here != NULL && tmp->ant_here->next == NULL) //ant_here pointing to last ant at the end
			return ;
		move(anthill, tmp); //one round
		ft_printf("\n");
	}
}