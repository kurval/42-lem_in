/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 11:34:26 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/27 10:56:44 by vkurkela         ###   ########.fr       */
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
    anthill->map = NULL;
    anthill->hashtable = NULL;
    anthill->paths = NULL;
	anthill->errnbr = 0;
	anthill->section = 0;
    anthill->line = 0;
    anthill->id = 0;
    anthill->quick = 0;
    anthill->reverse_path = NULL;
    anthill->tab = NULL;
}

int main(int arg, char **argc)
{
    t_lem_in    anthill;

    argc = NULL;
    init_anthill(&anthill);
    arg != 1 ? anthill.errnbr = 1 : 0;
    arg != 1 ? print_error(&anthill) : 0;
    parse_map(&anthill);
    validate_map(&anthill);
    print_map(&anthill);
    check_short(&anthill);
    if (!solver(&anthill) && anthill.quick != 1)
    {
        anthill.errnbr = 9;
        print_error(&anthill);
    }
    while (solver(&anthill));
    //ft_printf("ad\n");
    print_path(&anthill);
    //print_rooms(anthill.room);
    free_all(&anthill);
    return (0);
}