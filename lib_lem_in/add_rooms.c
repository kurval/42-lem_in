/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 12:38:06 by vkurkela          #+#    #+#             */
/*   Updated: 2020/06/21 10:26:44 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"

static t_room	*new_node(char *data, int x_c, int y_c, int id)
{
	t_room *room;

	if (!(room = (t_room*)malloc(sizeof(t_room))) ||\
	!(room->name = ft_strdup(data)))
		return (NULL);
	room->x = x_c;
	room->y = y_c;
	room->id = id;
	room->checked = 0;
	room->weight = 0;
	room->key = 0;
	room->connections = NULL;
	room->ant_here = NULL;
	room->prev = NULL;
	room->next = NULL;
	return (room);
}

int				add_room(t_lem_in **anthill, char *name, int x_c, int y_c)
{
	t_room	*node;
	t_room	**root;

	root = &(*anthill)->room;
	if (!(node = new_node(name, x_c, y_c, (*anthill)->id++)))
		return (0);
	node->next = *root;
	*root = node;
	return (1);
}
