/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 10:46:37 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/26 19:21:44 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	check_short(t_lem_in *anthill)
{
	t_connect   *current;
    t_path      *new_path;

    new_path = NULL;
	if (anthill->quick)
		return ;
	current = anthill->start->connections;
	while (current)
	{
		if (current->room == anthill->end)
		{
            new_path = add_path(&anthill->paths);
            if (!new_path || !(add_connection(&new_path->route, anthill->end)) ||\
            !(add_connection(&new_path->route, anthill->start)))
            {
                anthill->errnbr = 7;
                print_error(anthill);
            }
			anthill->quick = 1;
			return ;
		}
		current = current->next;
	}
	anthill->quick = -1;
}

void	reset_checked_rooms(t_lem_in *anthill)
{
	t_room	*current;

	current = anthill->room;
	while (current)
	{
		if (current->checked != 2)
			current->checked = 0;
		current = current->next;
	}
}