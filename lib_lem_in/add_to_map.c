/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:15:31 by vkurkela          #+#    #+#             */
/*   Updated: 2020/04/22 19:44:00 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"

void			print_map(t_lem_in *root)
{
	t_map *current;

	current = root->map;
	while (current)
	{
		write(1, current->line, ft_strlen(current->line));
		write(1, "\n", 1);
		current = current->next;
	}
	write(1, "\n", 1);
}

static t_map	*new_node(char *data)
{
	t_map *map;

	if (!(map = (t_map*)malloc(sizeof(t_map))) ||\
	!(map->line = ft_strdup(data)))
		return (NULL);
	map->next = NULL;
	return (map);
}

int				add_to_map(t_map **root, char *rule)
{
	t_map	*node;
	t_map	*temp;

	if (!(node = new_node(rule)))
		return (0);
	if (!*root)
	{
		*root = node;
		return (1);
	}
	temp = *root;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = node;
	return (1);
}
