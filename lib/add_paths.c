/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 12:38:06 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/27 10:55:09 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
/*
int		save_path(t_lem_in *lem_in)
{
	t_room	*tmp;
	t_path	*new_path;

	tmp = lem_in->end;
    new_path = add_path(&lem_in->paths);
	if (!new_path || !(add_connection(&new_path->route, tmp)))
    	return 0;
	while (tmp && tmp->path_prev && tmp->path_prev != lem_in->start)
	{
		tmp->path_prev->path_next = tmp;
		tmp = tmp->path_prev;
		tmp->checked = 2;
		if (!(add_connection(&new_path->route, tmp)))
        	return 0;
	}
	tmp = lem_in->start;
    if (!(add_connection(&new_path->route, tmp)))
        return 0;
	return (1);
}
*/
void	print_path(t_lem_in *anthill)
{
    t_path     	*path;
	t_connect   *current;
	int			i;

    path = anthill->paths;
	i = 0;
    while (path)
    {
        current = path->route;
		if (current)
			ft_printf(GREEN "PATH %d:\n" RESET, ++i);
		else
			return;
        while (current)
        {
            ft_printf("%s", current->room->name);
			if (current->room != anthill->end)
				ft_printf(GREEN " -> " RESET);
            current = current->next;
        }
		ft_printf("\n");
        path = path->next;
    }
}

static t_path	*new_path(void)
{
	t_path *path;

	if (!(path = (t_path*)malloc(sizeof(t_path))))
		return (NULL);
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