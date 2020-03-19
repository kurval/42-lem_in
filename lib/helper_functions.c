/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 15:57:24 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/19 19:22:30 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	print_hashes(t_lem_in *anthill)
{
	t_room		*current;
	t_hashtable	*colission;
	unsigned long	key;

	current = anthill->room;
	colission = NULL;
	key = 0;
	while(current)
	{
		key = hash(current->name, anthill->room_count);
		ft_printf("hashtable: key %d room %s\n", key, anthill->hashtable[key]->current->name);
		ft_printf("connections:\n");
		print_connections(anthill->hashtable[key]->connect);
		if (anthill->hashtable[key]->next != NULL)
		{
			colission = anthill->hashtable[key]->next;
			while (colission)
			{
				ft_printf("	colission room %s\n", colission->current->name);
				ft_printf("		connections:\n");
				print_connections(colission->connect);
				colission = colission->next;
			}
		}
		current = current->next;
	}
}

void	count_rooms(t_lem_in *anthill)
{
	t_room *current;

	current = anthill->room;
	while (current)
	{
		current = current->next;
		anthill->room_count += 1;
	}
}

void	free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}