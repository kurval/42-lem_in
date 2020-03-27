/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 12:38:06 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/27 14:56:23 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"

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