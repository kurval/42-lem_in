/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flows.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 13:01:46 by vkurkela          #+#    #+#             */
/*   Updated: 2020/06/25 11:58:20 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		is_edge_valid(t_lem_in *anthill, t_room *parent, t_room *connect)
{
	int id1;
	int id2;

	id1 = parent->id;
	id2 = connect->id;
	if (anthill->extra)
		return (anthill->flow[id1][id2] == 1);
	else if ((parent->weight + 1) < connect->weight ||\
	(parent->checked == 9 && connect == anthill->end))
		return (1);
	else
		return (!anthill->flow[id1][id2] ||\
				anthill->flow[id1][id2] == -1);
}

int		check_start_flow(t_lem_in *anthill)
{
	t_connect	*connects;
	t_room		*room;

	connects = anthill->start->connections;
	room = anthill->start;
	while (connects)
	{
		if (is_edge_valid(anthill, room, connects->room))
			return (1);
		connects = connects->next;
	}
	return (0);
}

void	update_flow(t_lem_in *anthill, t_room *parent, t_room *connect)
{
	int id1;
	int id2;

	id1 = parent->id;
	id2 = connect->id;
	if (!anthill->flow[id1][id2] && !anthill->flow[id2][id1])
	{
		anthill->flow[id1][id2] = 1;
		anthill->flow[id2][id1] = -1;
	}
	else if (anthill->flow[id1][id2] == -1 || anthill->extra)
	{
		parent->weight += 1;
		anthill->flow[id1][id2] = 0;
		anthill->flow[id2][id1] = 0;
	}
}

/*
** Creating flow chart to represent edges
** between nodes. Initializing them to 0.
*/

void	create_flow_chart(t_lem_in *anthill)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (!(anthill->flow = (int**)malloc(sizeof(int*) * anthill->room_count)))
		print_error(anthill, 7);
	while (i < anthill->room_count)
	{
		if (!(anthill->flow[i] = (int*)malloc(sizeof(int) *\
						anthill->room_count)))
			print_error(anthill, 7);
		j = 0;
		while (anthill->room_count > j)
		{
			anthill->flow[i][j] = 0;
			j++;
		}
		i++;
	}
}
