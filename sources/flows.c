/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flows.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 13:01:46 by vkurkela          #+#    #+#             */
/*   Updated: 2020/04/12 19:18:31 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		is_edge_valid(t_lem_in *anthill, int id1, int id2)
{
    if (anthill->extra)
    {
        if (anthill->flow[id1][id2] == 1)
            return (1);
    }
    else
    {
        if (!anthill->flow[id1][id2] ||\
                anthill->flow[id1][id2] == -1)
            return (1);
    }
	return (0);
}

int		check_start_flow(t_lem_in *anthill)
{
	t_connect	*connects;
	t_room		*room;

	connects = anthill->start->connections;
	room = anthill->start;
	while (connects)
	{
		if (is_edge_valid(anthill, room->id, connects->room->id))
			return (1);
		connects = connects->next;
	}
	return (0);
}

void	update_flow(t_lem_in *anthill, int id1, int id2)
{
	if (!anthill->flow[id1][id2] && !anthill->flow[id2][id1])
	{
		anthill->flow[id1][id2] = 1;
		anthill->flow[id2][id1] = -1;
	}
	else if (anthill->flow[id1][id2] == -1 || anthill->extra)
	{
		anthill->flow[id1][id2] = 0;
		anthill->flow[id2][id1] = 0;
	}
}

void	create_flow_chart(t_lem_in *anthill)
{
	unsigned int	i;

	i = 0;
	if (!(anthill->flow = (int**)malloc(sizeof(int*) * anthill->room_count)))
		print_error(anthill, 7);
	while (i < anthill->room_count)
	{
		if (!(anthill->flow[i++] = (int*)malloc(sizeof(int) *\
		anthill->room_count)))
			print_error(anthill, 7);
	}
}
