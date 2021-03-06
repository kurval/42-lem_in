/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 18:27:03 by vkurkela          #+#    #+#             */
/*   Updated: 2020/04/22 19:41:02 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"

static t_link	*new_link(char *from, char *to)
{
	t_link *link;

	if (!(link = (t_link*)malloc(sizeof(t_link))) ||\
	!(link->from = ft_strdup(from)) ||\
	!(link->to = ft_strdup(to)))
		return (NULL);
	link->next = NULL;
	return (link);
}

int				add_link(t_link **root, char *from, char *to)
{
	t_link	*node;

	if (!(node = new_link(from, to)))
		return (0);
	node->next = *root;
	*root = node;
	return (1);
}
