/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 19:34:38 by vkurkela          #+#    #+#             */
/*   Updated: 2020/04/15 16:03:38 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"

void		reset_checked_rooms(t_lem_in *anthill)
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

static int  check_dub(t_lem_in *anthill, t_room *room, t_path *path)
{
    if (room->checked == 4 && room != anthill->end)
    {
        path->type = -1;
        return (0);
    }
    return (1);
}

void update_rev_paths(t_lem_in *anthill, t_path *path)
{
    t_path      *current;
    t_connect   *temp;
    t_connect   *prev;
    int         i;

    current = path;
    reset_checked_rooms(anthill);
    while (current)
    {
        if (current->type != -1)
        {
            temp = current->route->next;
            prev = current->route;
            i = 0;
            while(temp)
            {
                i == 0 ? prev->room->prev = NULL : 0;
                i == 0 && prev->room->checked == 4 ? current->type = -1 : 0;
                if (check_dub(anthill, temp->room, current))
                {
                    temp->room->checked = 4;
                    temp->room->prev = prev->room;
                }
                prev = prev->next;
                temp = temp->next;
                i++;
            }
        }
        current = current->next;
    }
}
