/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:15:31 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/17 22:55:30 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	free_map(t_map *root)
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

void	print_map(t_lem_in *root)
{
	t_map *current;

	current = root->map;
	while(current)
	{
		ft_printf("%s\n", current->line);
		current = current->next;
	}
}

static t_map	*new_node(char *data)
{
	t_map *map;

	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	if (!(map->line = ft_strdup(data)))
		return (NULL);
	map->next = NULL;
	return (map);
}

int		add_to_map(t_map **root, char *rule)
{
	t_map	*node;
    t_map   *temp;

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