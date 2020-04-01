/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 15:57:24 by vkurkela          #+#    #+#             */
/*   Updated: 2020/04/01 11:48:20 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"

void	count_rooms(t_lem_in *anthill)
{
	t_room *current;

	current = anthill->room;
	while (current)
	{
		current = current->next;
		anthill->room_count += 1;
	}
}

void	free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_paths(t_path *root)
{
	t_path *temp;

	temp = NULL;
	if (!root)
		return ;
	while (root)
	{
		temp = root;
		root = root->next;
		free_connections(temp->route);
		free(temp);
	}
}

void	print_error(t_lem_in *anthill, int errnbr)
{
	errnbr == 1 ? ERROR(anthill->line, MESSAGE1) : 0;
	errnbr == 2 ? ERROR(anthill->line, MESSAGE2) : 0;
	errnbr == 3 ? ERROR(anthill->line, MESSAGE3) : 0;
	errnbr == 4 ? ERROR(anthill->line, MESSAGE4) : 0;
	errnbr == 5 ? ERROR(anthill->line, MESSAGE5) : 0;
	errnbr == 6 ? ERROR(anthill->line, MESSAGE6) : 0;
	errnbr == 7 ? ERROR(anthill->line, MESSAGE7) : 0;
	errnbr == 8 ? ERROR(anthill->line, MESSAGE8) : 0;
	errnbr == 9 ? ERROR(anthill->line, MESSAGE9) : 0;
	errnbr == 10 ? ERROR(anthill->line, MESSAGE10) : 0;
	errnbr == 11 ? ERROR(anthill->line, MESSAGE11) : 0;
	errnbr == 12 ? ERROR(anthill->line, MESSAGE12) : 0;
	errnbr == 13 ? ERROR(anthill->line, MESSAGE13) : 0;
	errnbr == 14 ? ERROR(anthill->line, MESSAGE14) : 0;
	errnbr == 15 ? ERROR(anthill->line, MESSAGE15) : 0;
	free_all(anthill);
	exit(0);
}

int		path_len(t_path *root)
{
	t_connect	*tmp;
	int			len;

	len = 0;
	if (!root->route)
		return (0);
	tmp = root->route;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}
