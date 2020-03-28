/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:15:31 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/28 15:09:21 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int  is_valid_room(t_room *root, char *name)
{
    while(root)
	{
		if (ft_strequ(root->name, name))
            return (1);
		root = root->next;
	}
    return (0);
}

void	check_start_end(t_lem_in *anthill, char *line)
{
	if (!ft_strncmp_end(line, "##start", 7) && !anthill->start)
		anthill->section= START;
	else if (!ft_strncmp_end(line, "##end", 5) && !anthill->end)
		anthill->section= END;
}

static int error_check(t_lem_in **anthill, char **tab, char *line, int *i)
{
    while (tab[*i])
        *i += 1;
    if (*i == 1 && (*anthill)->section!= START && (*anthill)->section!= END)
        return (1);
    (line[0] == 'L') ? (*anthill)->errnbr = 2 : 0;
    (*i != 3) ? (*anthill)->errnbr = 3 : 0;
    if (*i == 3)
    {
        (is_valid_room((*anthill)->room, tab[0])) ? (*anthill)->errnbr = 10 : 0;
        if (!ft_atoi_err(tab[1]) || !ft_atoi_err(tab[2]))
            (*anthill)->errnbr = 4;
    }
    if ((*anthill)->errnbr)
        return (0);
    else
        return (1);
}

static void push_room(t_lem_in **anthill, char **tab)
{
    if (!(add_room(&(*anthill)->room, tab[0])))
    {
        (*anthill)->errnbr = 7;
        return;
    }
    (*anthill)->section== START ? (*anthill)->start = (*anthill)->room : 0;
    (*anthill)->section== END ? (*anthill)->end = (*anthill)->room : 0;
    (*anthill)->section= ROOMS;
}

void check_rooms(t_lem_in **anthill, char *line)
{
    char    **tab;
    int     i;

    i = 0;
    if (!(tab = ft_strsplit(line, ' ')))
    {
        (*anthill)->errnbr = 7;
        return;
    }
    if (!error_check(anthill, tab, line, &i))
        return;
    if (i == 3)
        push_room(anthill, tab);
    else if (i == 1)
    {
        (*anthill)->section= LINKS;
        check_links(anthill, line);
        free_tab(tab);
        return ;
    }
    free_tab(tab);
}