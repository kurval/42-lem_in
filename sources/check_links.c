/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 18:20:36 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/11 19:10:31 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void error_check(t_lem_in **ant_hill, char **tab, int *i)
{
    while (tab[*i])
        *i += 1;
    if (*i != 2)
    {
        free_links((*ant_hill)->link);
        free(tab);
        exit(0);
    }
}

static void push_links(t_lem_in **ant_hill, char **tab)
{
    if (!(add_link(&(*ant_hill)->link, tab[0], tab[1])))
    {
        free_links((*ant_hill)->link);
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
        exit(0);
    error_check(ant_hill, tab, &i);
    push_links(ant_hill, tab);
    free(tab);
}