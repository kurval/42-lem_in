/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 11:27:44 by vkurkela          #+#    #+#             */
/*   Updated: 2020/04/17 11:33:08 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		reset_queue(t_connect *queue)
{
	t_connect *current;

	current = queue;
	while (current)
	{
		current->level = 0;
		current = current->next;
	}
}

/*
 ** Checks that edge is valid before end-node.
*/

static int	check_node(t_lem_in *anthill, t_connect *route, t_room **tmp)
{
	anthill->nodes += 1;
	if (route->room == anthill->end && *tmp != anthill->start &&\
			is_edge_valid(anthill, (*tmp)->id, anthill->end->id))
		return (1);
	else
		return (0);
}

/*
 ** Connect array adds next level of nodes to bfs
 ** if end is not reached.
*/

int			add_next_level(t_lem_in *anthill, t_room **array, t_path *path)
{
	int		ret;
	t_room	**new;

	ret = 0;
	new = NULL;
	if (!(new = connect_array(array, anthill->nodes, anthill)))
	{
		free(new);
		print_error(anthill, 7);
	}
	if (!anthill->nodes || !(bfs(anthill, new, path)))
		ret = 0;
	else
		ret = 1;
	free(new);
	return (ret);
}

/*
 ** Checks each connections of every room untill
 ** end is reached or function fails to find path.
*/

int			bfs(t_lem_in *anthill, t_room **array, t_path *path)
{
	t_room		**tmp;
	t_connect	*route;

	tmp = array;
	anthill->nodes = 0;
	anthill->level++;
	while (*tmp)
	{
		(*tmp)->checked != NEG ? (*tmp)->checked = VISITED : 0;
		route = (*tmp)->connections;
		while (route)
		{
			if (check_node(anthill, route, tmp))
				return (link_to_end(anthill, tmp, path));
			route = route->next;
		}
		(!(add_connect(&anthill->que, (*tmp)))) ?\
			print_error(anthill, 7) : 0;
		anthill->que->level = anthill->level;
		tmp++;
	}
	if (!(add_next_level(anthill, array, path)))
		return (0);
	return (1);
}
