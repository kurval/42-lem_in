/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 12:38:06 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/18 20:44:15 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	print_rooms(t_lem_in *root)
{
	t_room *current;

	current = root->room;
	while(current)
	{
		if (current == root->start)
			ft_printf("##start\n");
		else if (current == root->end)
			ft_printf("##end\n");
		ft_printf("%s x-%d y-%d\n", current->name, current->x, current->y);
		current = current->next;
	}
}

static t_room	*new_node(char *data, int x_c, int y_c)
{
	t_room *room;

	if (!(room = (t_room*)malloc(sizeof(t_room))))
		return (NULL);
	if (!(room->name = ft_strdup(data)))
		return (NULL);
	room->x = x_c;
	room->y = y_c;
	room->checked = 0;
	room->next = NULL;
	return (room);
}

int		add_room(t_room **root, char *name, int x_c, int y_c)
{
	t_room	*node;

	if (!(node = new_node(name, x_c, y_c)))
		return (0);
	node->next = *root;
	*root = node;
	return (1);
}