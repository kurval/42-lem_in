/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 11:34:26 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/17 20:52:39 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void    init_anthill(t_lem_in *anthill)
{
    anthill->ants = 0;
	anthill->room_count = 0;
	anthill->ant_lst = NULL;
	anthill->room = NULL;
	anthill->link = NULL;
    anthill->start = NULL;
	anthill->end = NULL;
	anthill->errnbr = 0;
	anthill->p = 0;
    anthill->line = 0;
}

int main(int arg, char **argc)
{
    t_lem_in    anthill;

    argc = NULL;
    init_anthill(&anthill);
    if (arg != 1)
        print_error(1, &anthill);
    parse_map(&anthill);
    if (!validate_map(&anthill))
        print_error(anthill.errnbr, &anthill);
    print_map(&anthill);
    free_links(anthill.link);
    free_rooms(anthill.room);
    free_ants(anthill.ant_lst);
    return (0);
}