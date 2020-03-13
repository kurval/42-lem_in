/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 11:34:26 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/13 21:11:21 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int main(int arg, char **argc)
{
    t_lem_in    ant_hill;

    argc = NULL;
    if (arg != 1)
        print_error(1, &ant_hill);
    parse_map(&ant_hill);
    validate_map(&ant_hill);
    if (ant_hill.errnbr)
        print_error(ant_hill.errnbr, &ant_hill);
    
    ft_printf("ants: %d\n", ant_hill.ants);
    ft_printf("\nrooms:\n");
    print_rooms(ant_hill.room);
    ft_printf("\nstart: %s\n", ant_hill.start->name);
    ft_printf("end: %s\n", ant_hill.end->name);
    ft_printf("\nlinks:\n");
    print_links(ant_hill.link);
    ft_printf("\nANTS:\n");
    print_ants(ant_hill.ant_lst);
    free_links(ant_hill.link);
    free_rooms(ant_hill.room);
    free_ants(ant_hill.ant_lst);
    return (0);
}