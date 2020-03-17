/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 18:27:03 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/17 13:38:28 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	print_links(t_link *root)
{
	while(root)
	{
		ft_printf("%s-%s\n", root->from, root->to);
		root = root->next;
	}
}

static t_link   *new_link(char *from, char *to)
{
	t_link *link;

	if (!(link = (t_link*)malloc(sizeof(t_link))))
		return (NULL);
	if (!(link->from = ft_strdup(from)))
		return (NULL);
    if (!(link->to = ft_strdup(to)))
		return (NULL);
	link->next = NULL;
	free (from);
	free (to);
	return (link);
}

int		add_link(t_link **root, char *from, char *to)
{
	t_link	*node;

	if (!(node = new_link(from, to)))
		return (0);
	node->next = *root;
	*root = node;
	return (1);
}