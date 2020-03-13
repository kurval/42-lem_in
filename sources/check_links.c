/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 18:20:36 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/13 13:34:47 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int  is_valid_link(t_link *root, char *room1, char *room2)
{
    int len1;
    int len2;

    len1 = ft_strlen(room1);
    len2 = ft_strlen(room2);
    while(root)
	{
		if (!ft_strncmp_end(root->from, room1, len1) &&\
        !ft_strncmp_end(root->to, room2, len2))
            return (0);
		root = root->next;
	}
    return (1);
}

static int error_check(t_lem_in **ant_hill, char **tab, int *i)
{
    while (tab[*i])
        *i += 1;
    (*i != 2) ? (*ant_hill)->errnbr = 5 : 0;
    if (*i == 2)
    {
        !is_valid_link((*ant_hill)->link, tab[0], tab[1]) ? (*ant_hill)->errnbr = 11 : 0;
        !is_valid_room((*ant_hill)->room, tab[0]) ? (*ant_hill)->errnbr = 6 : 0;
        !is_valid_room((*ant_hill)->room, tab[1]) ? (*ant_hill)->errnbr = 6 : 0;
    }
    if ((*ant_hill)->errnbr)
    {
        free(tab);
        return (0);
    }
    return (1);
}

static void push_link(t_lem_in **ant_hill, char **tab)
{
    if (!(add_link(&(*ant_hill)->link, tab[0], tab[1])))
        (*ant_hill)->errnbr = 7;
}

void check_links(t_lem_in **ant_hill, char *line)
{
    char    **tab;
    int     i;

    i = 0;
    if (!(tab = ft_strsplit(line, '-')))
    {
        (*ant_hill)->errnbr = 7;
        return;
    }
    if (!error_check(ant_hill, tab, &i))
        return;
    push_link(ant_hill, tab);
    free(tab);
}