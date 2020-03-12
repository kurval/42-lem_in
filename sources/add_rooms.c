/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 12:38:06 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/12 20:36:53 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	print_rooms(t_room *root)
{
	while(root)
	{
		ft_printf("%s x-%d y-%d\n", root->name, root->x, root->y);
		root = root->next;
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