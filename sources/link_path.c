/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 11:29:57 by vkurkela          #+#    #+#             */
/*   Updated: 2020/04/17 11:21:58 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
 ** Links previous node to end of the shortest path.
*/

int			link_to_end(t_lem_in *anthill, t_room **tmp, t_path *path)
{
	anthill->end->checked = PATH;
	if (!(add_connect(&path->route, anthill->end)))
		print_error(anthill, 7);
	anthill->reverse_path = *tmp;
	path->second_last = *tmp;
	update_flow(anthill, (*tmp)->id, anthill->end->id);
	(*tmp)->checked = PATH;
	if (!(add_connect(&path->route, *tmp)))
		print_error(anthill, 7);
	return (1);
}

static void	create_link(t_lem_in *anthill, t_connect *tmp,\
t_connect *route, t_path *path)
{
	update_flow(anthill, tmp->room->id, route->room->id);
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
	int			lev;

	tmp = queue;
	lev = 0;
	while (tmp)
	{
		route = tmp->room->connections;
		while (route)
		{
			if (route->room == anthill->reverse_path &&\
			tmp->level != lev)
			{
				create_link(anthill, tmp, route, path);
				lev = tmp->level;
			}
			route = route->next;
		}
		tmp = tmp->next;
	}
}
