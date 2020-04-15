/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 15:45:02 by vkurkela          #+#    #+#             */
/*   Updated: 2020/04/15 20:44:11 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	count_connections(t_room *room)
{
	t_connect	*current;
	int			count;

	count = 0;
	current = room->connections;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

static int	check_neg_paths(t_lem_in *anthill)
{
	t_path	*current;

	current = anthill->paths;
	while (current)
	{
		if (current->type == NEG)
			return (1);
		current = current->next;
	}
	return (0);
}

int			check_max_paths(t_lem_in *anthill)
{
	int	start_con;
	int	end_con;
	int	max;

	max = 0;
	start_con = count_connections(anthill->start);
	end_con = count_connections(anthill->end);
	max = (start_con < end_con) ? start_con : end_con;
	if (anthill->nb_paths < max && check_neg_paths(anthill))
		return (0);
	return (1);
}
