/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 15:57:24 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/17 22:57:44 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

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

void	free_links(t_link *root)
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

void	free_rooms(t_room *root)
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