/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 18:20:36 by vkurkela          #+#    #+#             */
/*   Updated: 2020/04/01 12:01:11 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	is_valid_link(t_lem_in *anthill, char *room1, char *room2)
{
	t_link *current;

	if (ft_strequ(room1, room2))
	{
		anthill->errnbr = 15;
		return ;
	}
	current = anthill->link;
	while (current)
	{
		if ((ft_strequ(current->from, room1) &&\
					ft_strequ(current->to, room2)) ||\
				(ft_strequ(current->to, room1) &&\
				ft_strequ(current->from, room2)))
		{
			anthill->errnbr = 11;
			return ;
		}
		current = current->next;
	}
}

static int	error_check(t_lem_in **anthill, char **tab, int *i)
{
	while (tab[*i])
		*i += 1;
	(*i != 2) ? (*anthill)->errnbr = 5 : 0;
	if (*i == 2)
	{
		is_valid_link(*anthill, tab[0], tab[1]);
		if (!is_valid_room((*anthill)->room, tab[0]) ||\
				!is_valid_room((*anthill)->room, tab[1]))
			(*anthill)->errnbr = 6;
	}
	if ((*anthill)->errnbr)
	{
		free_tab(tab);
		return (0);
	}
	return (1);
}

void		check_links(t_lem_in **anthill, char *line)
{
	char	**tab;
	int     i;

	i = 0;
	if (!(tab = ft_strsplit(line, '-')))
	{
		(*anthill)->errnbr = 7;
		return ;
	}
	if (!error_check(anthill, tab, &i))
		return ;
	if (!(add_link(&(*anthill)->link, tab[0], tab[1])))
		(*anthill)->errnbr = 7;
	free_tab(tab);
}
