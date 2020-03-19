/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_connections.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 15:41:13 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/19 19:20:44 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	print_connections(t_connect *root)
{
	t_connect *current;

	current = root;
	while(current)
	{
		ft_printf("%s\n", current->room->name);
		current = current->next;
	}
}

static t_connect	*new_connect(t_room *to)
{
	t_connect *connect;

	if (!(connect = (t_connect*)malloc(sizeof(t_connect))))
		return (NULL);
	connect->room = to;
	connect->next = NULL;
	return (connect);
}

static int		add_connection(t_connect **root, t_room *to)
{
	t_connect	*node;

	if (!(node = new_connect(to)))
		return (0);
	node->next = *root;
	*root = node;
	return (1);
}

static t_hashtable   *check_room(t_hashtable *table, char *room)
{
    t_hashtable *ptr;
    int         len;

    ptr = table;
    len = ft_strlen(room);
    if (!ft_strncmp_end(ptr->current->name, room, len))
        return (ptr);
    else
        while (ptr)
        {
            if (!ft_strncmp_end(ptr->current->name, room, len))
                return (ptr);
            ptr = ptr->next;
        }
    return (table);
}

void       create_connections(t_lem_in *anthill)
{
    t_link			*tmp;
	unsigned long	key_from;
    unsigned long	key_to;
    t_hashtable      *from;
    t_hashtable      *to;
    
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
        if (!(add_connection(&from->connect, to->current)))
             anthill->errnbr = 7;
		tmp = tmp->next;
	}
}