/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 11:34:26 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/11 19:39:41 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int main(int arg, char **argc)
{
    t_lem_in    ant_hill;

    argc = NULL;
    if (arg != 1)
        return (0);
    parse_map(&ant_hill);
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