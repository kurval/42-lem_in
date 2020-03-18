/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_hashtable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 13:32:33 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/18 15:41:48 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/* 
** djb2 hash function
** ((hash << 5) + hash) + c means:
** hash * 33 + c
*/

unsigned long       hash(char *str, int count)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;

    return (hash % count);
}

static t_hashtable  *create_bucket(t_room *room, unsigned long key)
{
	t_hashtable *bucket;

	if (!(bucket = (t_hashtable*)malloc(sizeof(t_hashtable))))
		return (NULL);
    bucket->current = room;
    bucket->key = key;
    bucket->connect = NULL;
	bucket->next = NULL;
	return (bucket);
}

static void     chain_collission(t_lem_in **anthill, t_room *room, unsigned long key)
{
	t_hashtable *new;

    new = create_bucket(room, key);
    new->next = (*anthill)->hashtable[key];
	(*anthill)->hashtable[key] = new;
}

void        insert_data(t_lem_in *anthill)
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
			anthill->hashtable[key] = create_bucket(tmp, key);
		tmp = tmp->next;
	}
}

void            create_hashtable(t_lem_in *anthill)
{
	unsigned int	i;

	i = 0;
	if (!(anthill->hashtable = (t_hashtable**)malloc(sizeof(t_hashtable)\
	* anthill->room_count * SIZE)))
        anthill->errnbr = 7;
	while (i < anthill->room_count * SIZE)
		anthill->hashtable[i++] = NULL;
    insert_data(anthill);
}