/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 12:38:06 by vkurkela          #+#    #+#             */
/*   Updated: 2020/04/07 14:55:43 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"

static t_room	*new_node(char *data, int x_c, int y_c, int id)
{
	t_room *room;

	if (!(room = (t_room*)malloc(sizeof(t_room))))
		return (NULL);
	if (!(room->name = ft_strdup(data)))
		return (NULL);
	room->x = x_c;
	room->y = y_c;
	room->id = id;
	room->checked = 0;
	room->key = 0;
	room->connections = NULL;
	room->ant_here = NULL;
	room->prev = NULL;
	room->next = NULL;
	return (room);
}

int				add_room(t_room **root, char *name, int x_c, int y_c, int id)
{
	t_room	*node;

	if (!(node = new_node(name, x_c, y_c, id)))
		return (0);
	node->next = *root;
	*root = node;
	return (1);
}
