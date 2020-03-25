/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 12:38:06 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/25 07:45:18 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	save_path(t_lem_in *lem_in)
{
	t_room	*tmp;

	tmp = lem_in->end;
    add_path(&lem_in->paths);
    add_connection(&lem_in->paths->route, tmp);
	while (tmp && tmp->path_prev && tmp->path_prev != lem_in->start)
	{
		tmp->path_prev->path_next = tmp;
		tmp = tmp->path_prev;
        add_connection(&lem_in->paths->route, tmp);
	}
	tmp = lem_in->start;
    add_connection(&lem_in->paths->route, tmp);
}

void	print_path(t_lem_in *anthill)
{
    t_path     *path;
	t_connect   *current;
	int			i;

    path = anthill->paths;
	i = 0;
    while (path)
    {
        current = path->route;
		ft_printf(GREEN "PATH %d:\n" RESET, ++i);
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

int		add_path(t_path **root)
{
	t_path	*node;

	if (!(node = new_path()))
		return (0);
	node->next = *root;
	*root = node;
	return (1);
}