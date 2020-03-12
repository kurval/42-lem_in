/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 11:34:26 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/12 14:01:18 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int main(int arg, char **argc)
{
    t_lem_in    ant_hill;

    argc = NULL;
    if (arg != 1)
        print_error(1);
    parse_map(&ant_hill);
    if (ant_hill.errnbr)
        print_error(ant_hill.errnbr);
    ft_printf("ants: %d\n", ant_hill.ants);
    ft_printf("\nrooms:\n");
    print_rooms(ant_hill.room);
    ft_printf("\nstart: %s\n", ant_hill.start->name);
    ft_printf("end: %s\n", ant_hill.end->name);
    ft_printf("\nlinks:\n");
    print_links(ant_hill.link);
    free_links(ant_hill.link);
    free_rooms(ant_hill.room);
    return (0);
}