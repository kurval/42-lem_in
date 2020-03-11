/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 12:38:06 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/11 15:15:46 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	check_start_end(char *line, int *nbr)
{
	if (!ft_strncmp_end(line, "##start", 7))
		*nbr = 2;
	else if (!ft_strncmp_end(line, "##end", 5))
		*nbr = 3;
	else
		exit(0);
}

void	print_rooms(t_room *root)
{
	while(root)
	{
		ft_printf("%s %d %d\n", root->name, root->x, root->y);
		root = root->next;
	}
}

t_room	*new_node(char *data, int x_c, int y_c)
{
	t_room *room;

	room = (t_room*)malloc(sizeof(t_room));
	room->name = ft_strdup(data);
	room->x = x_c;
	room->y = y_c;
	room->next = NULL;
	return (room);
}

void	add_room(t_room **root, char *name, int x_c, int y_c)
{
	t_room	*node;

	node = new_node(name, x_c, y_c);
	node->next = *root;
	*root = node;
}