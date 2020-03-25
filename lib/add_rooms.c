/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 12:38:06 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/25 10:56:30 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	print_rooms(t_room *root)
{
	t_room   *current;

    current = root;
    while(current)
    {
        ft_printf("room %s checked %d\n", current->name, current->checked);
        current = current->next;
    }
}

static t_room	*new_node(char *data, int nbr)
{
	t_room *room;

	if (!(room = (t_room*)malloc(sizeof(t_room))))
		return (NULL);
	if (!(room->name = ft_strdup(data)))
		return (NULL);
	room->checked = 0;
	room->key = 0;
	room->id = nbr;
	room->connections = NULL;
	room->ant_here = NULL;
	room->next = NULL;
	room->path_next = NULL;
	room->path_prev = NULL;
	return (room);
}

int		add_room(t_room **root, char *name, int id)
{
	t_room	*node;

	if (!(node = new_node(name, id)))
		return (0);
	node->next = *root;
	*root = node;
	return (1);
}