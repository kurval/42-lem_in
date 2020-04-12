/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_short.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 20:55:10 by vkurkela          #+#    #+#             */
/*   Updated: 2020/04/11 15:30:42 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		check_short(t_lem_in *anthill)
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
            update_flow(anthill, anthill->start->id, anthill->end->id);
			new_path->second_last = anthill->start;
			new_path->nb = anthill->nb_paths++;
			return ;
		}
		current = current->next;
	}
	anthill->quick = -1;
}
