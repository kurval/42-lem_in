/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_connections.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 15:41:13 by vkurkela          #+#    #+#             */
/*   Updated: 2020/06/21 11:47:59 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"

static t_connect	*new_connect(t_room *to)
{
	t_connect *connect;

	if (!(connect = (t_connect*)malloc(sizeof(t_connect))))
		return (NULL);
	connect->level = 0;
	connect->room = to;
	connect->next = NULL;
	return (connect);
}

int					add_connect(t_connect **root, t_room *to)
{
	t_connect	*node;

	if (!(node = new_connect(to)))
		return (0);
	node->next = *root;
	*root = node;
	return (1);
}

/*
 ** Checking room name incase of collissions and
 ** returning right hashtable.
*/

static t_hashtable	*check_room(t_hashtable *table, char *room)
{
	t_hashtable *ptr;

	ptr = table;
	if (ft_strequ(ptr->current->name, room))
		return (ptr);
	else
		while (ptr)
		{
			if (ft_strequ(ptr->current->name, room))
				return (ptr);
			ptr = ptr->next;
		}
	return (table);
}

/*
 ** Getting keys and adding connections for rooms.
*/

void				create_connections(t_lem_in *anthill)
{
	t_link			*tmp;
	unsigned long	key_from;
	unsigned long	key_to;
	t_hashtable		*from;
	t_hashtable		*to;

	tmp = anthill->link;
	key_from = 0;
	key_to = 0;
	from = NULL;
	to = NULL;
	while (tmp != NULL)
	{
		key_from = hash(tmp->from, anthill->room_count);
		key_to = hash(tmp->to, anthill->room_count);
		from = check_room(anthill->hashtable[key_from], tmp->from);
		to = check_room(anthill->hashtable[key_to], tmp->to);
		if (!(add_connect(&from->connect, to->current)) ||\
				!(add_connect(&to->connect, from->current)))
			print_error(anthill, 7);
		from->current->connections = from->connect;
		to->current->connections = to->connect;
		tmp = tmp->next;
	}
}
