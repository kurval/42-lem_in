/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:15:31 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/13 21:05:37 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int  is_valid_room(t_room *root, char *name)
{
    int len;

    len = ft_strlen(name);
    while(root)
	{
		if (!ft_strncmp_end(root->name, name, len))
            return (1);
		root = root->next;
	}
    return (0);
}

void	check_start_end(t_lem_in *ant_hill, char *line)
{
	if (!ft_strncmp_end(line, "##start", 7) && !ant_hill->start)
		ant_hill->p = START;
	else if (!ft_strncmp_end(line, "##end", 5) && !ant_hill->end)
		ant_hill->p = END;
	else
	    ant_hill->errnbr = 9;
}

static int error_check(t_lem_in **ant_hill, char **tab, char *line, int *i)
{
    while (tab[*i])
        *i += 1;
    if (*i == 1 && (*ant_hill)->p != START && (*ant_hill)->p != END)
        return (1);
    (line[0] == 'L') ? (*ant_hill)->errnbr = 2 : 0;
    (*i != 3) ? (*ant_hill)->errnbr = 3 : 0;
    if (*i == 3)
    {
        (is_valid_room((*ant_hill)->room, tab[0])) ? (*ant_hill)->errnbr = 10 : 0;
        (!ft_atoi_err(tab[1])) ? (*ant_hill)->errnbr = 4 : 0;
        (!ft_atoi_err(tab[2])) ? (*ant_hill)->errnbr = 4 : 0;
    }
    if ((*ant_hill)->errnbr)
    {
        free(tab);
        return (0);
    }
    else
        return (1);
}

static void push_room(t_lem_in **ant_hill, char **tab)
{
    if (!(add_room(&(*ant_hill)->room, tab[0], ft_atoi(tab[1]), ft_atoi(tab[2]))))
    {
        (*ant_hill)->errnbr = 7;
        return;
    }
    (*ant_hill)->p == START ? (*ant_hill)->start = (*ant_hill)->room : 0;
    (*ant_hill)->p == END ? (*ant_hill)->end = (*ant_hill)->room : 0;
    (*ant_hill)->p = ROOMS;
}

void check_rooms(t_lem_in **ant_hill, char *line)
{
    char    **tab;
    int     i;

    i = 0;
    if (!(tab = ft_strsplit(line, ' ')))
    {
        (*ant_hill)->errnbr = 7;
        return;
    }
    if (!error_check(ant_hill, tab, line, &i))
        return;
    if (i == 3)
        push_room(ant_hill, tab);
    else if (i == 1)
    {
        (*ant_hill)->p = LINKS;
        check_links(ant_hill, line);
    }
    free(tab);
}