/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_short.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 20:55:10 by vkurkela          #+#    #+#             */
/*   Updated: 2020/04/16 14:00:03 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	save_path_info(t_lem_in *anthill, t_path *new_path)
{
	update_flow(anthill, anthill->start->id, anthill->end->id);
	new_path->second_last = anthill->start;
	new_path->nb = ++anthill->nb_paths;
	new_path->len = path_len(new_path);
}

void		check_short(t_lem_in *anthill)
{
	t_connect	*current;
	t_path		*new_path;

	new_path = NULL;
	current = anthill->start->connections;
	while (current)
	{
		if (current->room == anthill->end)
		{
			new_path = !anthill->extra ? add_path(&anthill->paths) :\
			add_path(&anthill->paths2);
			if (!new_path || !(add_connect(&new_path->route, anthill->end)) ||\
					!(add_connect(&new_path->route, anthill->start)))
				print_error(anthill, 7);
			save_path_info(anthill, new_path);
			return ;
		}
		current = current->next;
	}
}
