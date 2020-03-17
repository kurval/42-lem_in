/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 20:51:11 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/17 20:55:03 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void    print_map(t_lem_in *map)
{
    ft_printf("ants:\n%d\n", map->ants);
    ft_printf("\nrooms:\n");
    print_rooms(map);
    ft_printf("\nlinks:\n");
    print_links(map->link);
    ft_printf("\nANTS:\n");
    print_ants(map->ant_lst);
}