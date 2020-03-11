/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 18:20:36 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/11 19:45:18 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int  is_valid_room(t_room *root, char *name)
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

static void error_check(t_lem_in **ant_hill, char **tab, int *i)
{
    while (tab[*i])
        *i += 1;
    if (*i != 2)
    {
        free_links((*ant_hill)->link);
        free_rooms((*ant_hill)->room);
        free(tab);
        exit(0);
    }
    if (!is_valid_room((*ant_hill)->room, tab[0]) ||\
    !is_valid_room((*ant_hill)->room, tab[1]))
    {
        free_links((*ant_hill)->link);
        free_rooms((*ant_hill)->room);
        free(tab);
        exit(0);
    }
}

static void push_link(t_lem_in **ant_hill, char **tab)
{
    if (!(add_link(&(*ant_hill)->link, tab[0], tab[1])))
    {
        free_links((*ant_hill)->link);
        free_rooms((*ant_hill)->room);
        free(tab);
        exit(0);
    }
}

void check_links(t_lem_in **ant_hill, char *line)
{
    char    **tab;
    int     i;

    i = 0;
    if (!(tab = ft_strsplit(line, '-')))
    {
        free_rooms((*ant_hill)->room);
        exit(0);
    }
    error_check(ant_hill, tab, &i);
    push_link(ant_hill, tab);
    free(tab);
}