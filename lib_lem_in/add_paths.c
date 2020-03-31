/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 12:38:06 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/31 16:56:15 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"

static t_path	*new_path(void)
{
	t_path *path;

	if (!(path = (t_path*)malloc(sizeof(t_path))))
		return (NULL);
	path->nb = 0;
	path->len = 0;
	path->second_last = NULL;
	path->route = NULL;
	path->next = NULL;
	return (path);
}

t_path	*add_path(t_path **root)
{
	t_path	*path;
	t_path  *temp;

	if (!(path = new_path()))
		return (NULL);
	if (!*root)
    {
	    *root = path;
        return (path);
    }
    temp = *root;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = path;
	return (path);
}

static void	del_node(t_path **node)
{
	if (node != NULL && *node != NULL)
	{
		free(*node);
		*node = NULL;
	}
}

void	del_last(t_path **root)
{
	t_path  *second_last;

	if (!*root)
		return;
	if (!(*root)->next)
	{
		del_node(root);
		return ;
	}
	second_last = *root;
	while (second_last->next->next)
		second_last = second_last->next;
	del_node(&second_last->next);
	second_last->next = NULL;
}

void	del_start(t_path **root)
{
	t_connect  *tmp;

	if (!(*root)->route)
		return;
	tmp = (*root)->route;
	(*root)->route = (*root)->route->next;
	(*root)->route->room->prev = NULL;
	free(tmp);
}
