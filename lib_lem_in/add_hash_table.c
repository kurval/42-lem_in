/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_hash_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 11:46:15 by vkurkela          #+#    #+#             */
/*   Updated: 2020/04/22 20:02:49 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"

/*
** djb2 hash function
** ((hash << 5) + hash) + c means:
** hash * 33 + c
*/

unsigned long		hash(char *str, int count)
{
	unsigned long	hash;
	int				c;

	hash = 5381;
	while ((c = *str++))
		hash = ((hash << 5) + hash) + c;
	return (hash % (count * 100));
}

static t_hashtable	*create_bucket(t_room *room, unsigned long key)
{
	t_hashtable	*bucket;

	if (!(bucket = (t_hashtable*)malloc(sizeof(t_hashtable))))
		return (NULL);
	room->key = key;
	bucket->current = room;
	bucket->key = key;
	bucket->connect = NULL;
	bucket->next = NULL;
	return (bucket);
}

/*
 ** Adding bucket to head of the list.
*/

static void			chain_collission(t_lem_in **anthill, t_room *room,\
unsigned long key)
{
	t_hashtable *new;

	if (!(new = create_bucket(room, key)))
		print_error(*anthill, 7);
	new->next = (*anthill)->hashtable[key];
	(*anthill)->hashtable[key] = new;
}

/*
 ** Creating bucket for each of the rooms. Handling
 ** collisions if there is another room with same key.
*/ 

void				insert_data(t_lem_in *anthill)
{
	t_room			*tmp;
	unsigned long	key;

	tmp = anthill->room;
	key = 0;
	while (tmp != NULL)
	{
		key = hash(tmp->name, anthill->room_count);
		if (anthill->hashtable[key] != NULL)
			chain_collission(&anthill, tmp, key);
		else
			if (!(anthill->hashtable[key] = create_bucket(tmp, key)))
				print_error(anthill, 7);
		tmp = tmp->next;
	}
}

void				create_hashtable(t_lem_in *anthill)
{
	unsigned long	i;

	i = 0;
	if (!(anthill->hashtable = (t_hashtable**)malloc(sizeof(t_hashtable)\
					* anthill->room_count * SIZE)))
		print_error(anthill, 7);
	while (i < anthill->room_count * SIZE)
		anthill->hashtable[i++] = NULL;
	insert_data(anthill);
}
