/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_hashtable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 20:06:25 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/19 20:34:35 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static void free_connections(t_connect *root)
{
    t_connect *temp;

	temp = NULL;
	if (!root)
		return ;
	while (root)
	{
		temp = root;
		root = root->next;
		free(temp);
	}
}

static void free_hashes(t_hashtable *root)
{
    t_hashtable *temp;

	temp = NULL;
	if (!root)
		return ;
	while (root)
	{
		temp = root;
        free_connections(temp->connect);
		root = root->next;
		free(temp);
	}
}

void    free_hashtable(t_lem_in *anthill)
{
    int key;

    key = 0;
    if (!anthill->hashtable)
		return ;
    while (anthill->room)
    {
        key = hash(anthill->room->name, anthill->room_count);
        free_hashes(anthill->hashtable[key]);
        anthill->room = anthill->room->next;
    }
}