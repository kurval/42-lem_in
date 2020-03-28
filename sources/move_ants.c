/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 10:50:09 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/28 20:33:19 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void make_moves(t_lem_in *anthill, t_room *tmp)
{
    while (1)
	{
		tmp = anthill->end;
		if (tmp->ant_here != NULL && tmp->ant_here->next == NULL)
			return ;
		while (tmp)
		{
			if (tmp->prev && tmp->prev->ant_here && !tmp->ant_here)
			{
				tmp->ant_here = tmp->prev->ant_here;
				MOVE(tmp->ant_here->name, tmp->name);
			}
			else if (tmp->ant_here)
			{
				tmp->ant_here = tmp->ant_here->next;
				if (tmp != anthill->start && tmp->ant_here)
					MOVE(tmp->ant_here->name, tmp->name);
			}
			tmp = tmp->prev;
		}
		ft_printf("\n");
	}
}

void	move_ants(t_lem_in *anthill)
{
	t_room	*tmp;

    tmp = NULL;
    anthill->start->ant_here = anthill->ant_lst;
    anthill->end->prev = anthill->paths->second_last;
    make_moves(anthill, tmp);
}