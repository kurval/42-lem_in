/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 20:16:51 by vkurkela          #+#    #+#             */
/*   Updated: 2020/04/01 11:53:33 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"

static t_ants	*new_node(long data)
{
	t_ants *ants;

	if (!(ants = (t_ants*)malloc(sizeof(t_ants))))
		return (NULL);
	if (!(ants->name = data))
		return (NULL);
	ants->next = NULL;
	return (ants);
}

int				add_ants(t_ants **root, long name)
{
	t_ants	*node;

	while (name > 0)
	{
		if (!(node = new_node(name)))
			return (0);
		node->next = *root;
		*root = node;
		name--;
	}
	return (1);
}
