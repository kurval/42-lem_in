/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 11:29:57 by vkurkela          #+#    #+#             */
/*   Updated: 2020/04/12 19:28:27 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void create_link(t_lem_in *anthill, t_connect *tmp, t_connect *route, t_path *path)
{
    update_flow(anthill, tmp->room->id, route->room->id);
    if (!anthill->reverse_path->prev && !anthill->reverse_path->second)
        anthill->reverse_path->prev = tmp->room;
    tmp->room->checked == NEG ? path->type = NEG : 0;
    anthill->reverse_path = tmp->room;
    if (!(add_connect(&path->route, tmp->room)))
        print_error(anthill, 7);
    tmp->room->checked = PATH;
}

/*
 ** Retrace shortest path back to start.
*/

void		link_path(t_lem_in *anthill, t_connect *queue, t_path *path)
{
	t_connect	*tmp;
	t_connect	*route;

	tmp = queue;
	while (path->route->room != anthill->start)
	{
		route = tmp->room->connections;
		while (route)
		{
			if (route->room == anthill->reverse_path &&\
			is_edge_valid(anthill, tmp->room->id, route->room->id) &&\
			tmp->room->checked != PATH)
                create_link(anthill, tmp, route, path);
			route = route->next;
		}
		tmp = (tmp->next) ? tmp->next : queue;
	}
}