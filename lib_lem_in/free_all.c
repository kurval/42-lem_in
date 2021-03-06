/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 23:08:38 by vkurkela          #+#    #+#             */
/*   Updated: 2020/06/25 18:45:56 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"

static void	free_links(t_link *root)
{
	t_link *temp;

	temp = NULL;
	if (!root)
		return ;
	while (root)
	{
		temp = root;
		root = root->next;
		free(temp->to);
		free(temp->from);
		free(temp);
	}
}

static void	free_rooms(t_room *root)
{
	t_room *temp;

	temp = NULL;
	if (!root)
		return ;
	while (root)
	{
		temp = root;
		root = root->next;
		free(temp->name);
		free(temp);
	}
}

static void	free_ants(t_ants *root)
{
	t_ants *temp;

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

static void	free_map(t_map *root)
{
	t_map *temp;

	temp = NULL;
	if (!root)
		return ;
	while (root)
	{
		temp = root;
		root = root->next;
		free(temp->line);
		free(temp);
	}
}

void		free_all(t_lem_in *anthill)
{
	free(anthill->flags);
	free_hashtable(anthill);
	free_paths(anthill->paths);
	free_paths(anthill->paths2);
	free_flow_chart(anthill);
	free_links(anthill->link);
	free_rooms(anthill->room);
	free_ants(anthill->ant_lst);
	free_map(anthill->map);
}
