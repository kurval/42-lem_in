/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:15:31 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/11 16:49:26 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void error_check(t_lem_in **ant_hill, char **tab, char *line, int *i)
{
    while (tab[*i])
        *i += 1;
    if (line[0] == 'L' || (*i != 3 && *i != 1) ||\
    !ft_atoi_err(tab[1]) || !ft_atoi_err(tab[2]))
    {
        free_rooms((*ant_hill)->room);
        free(tab);
        exit(0);
    }
}

static void push_room(t_lem_in **ant_hill, char **tab, int *nbr)
{
    if (!(add_room(&(*ant_hill)->room, tab[0], ft_atoi(tab[1]), ft_atoi(tab[2]))))
    {
        free_rooms((*ant_hill)->room);
        free(tab);
        exit(0);
    }
    *nbr == START ? (*ant_hill)->start = (*ant_hill)->room : 0;
    *nbr == END ? (*ant_hill)->end = (*ant_hill)->room : 0;
    *nbr = ROOMS;
}

void check_rooms(t_lem_in **ant_hill, char *line, int *nbr)
{
    char    **tab;
    int     i;

    i = 0;
    if (!(tab = ft_strsplit(line, ' ')))
        exit(0);
    error_check(ant_hill, tab, line, &i);
    if (i == 3)
        push_room(ant_hill, tab, nbr); 
    else if (i == 1)
        *nbr = LINKS;
    free(tab);
}