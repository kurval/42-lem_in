/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 12:38:06 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/31 16:52:21 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"

static t_room	*new_node(char *data)
{
	t_room *room;

	if (!(room = (t_room*)malloc(sizeof(t_room))))
		return (NULL);
	if (!(room->name = ft_strdup(data)))
		return (NULL);
	room->checked = 0;
	room->key = 0;
	room->connections = NULL;
	room->ant_here = NULL;
	room->prev = NULL;
	room->next = NULL;
	return (room);
}

int		add_room(t_room **root, char *name)
{
	t_room	*node;

	if (!(node = new_node(name)))
		return (0);
	node->next = *root;
	*root = node;
	return (1);
}