/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flows.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 13:01:46 by vkurkela          #+#    #+#             */
/*   Updated: 2020/04/07 15:31:21 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void    create_flow_chart(t_lem_in *anthill)
{
    unsigned int    i;

    i = 0;
    if (!(anthill->flow = (int**)malloc(sizeof(int*) * anthill->room_count)))
        print_error(anthill, 7);
    while (i < anthill->room_count)
    {
        if (!(anthill->flow[i++] = (int*)malloc(sizeof(int) * anthill->room_count)))
            print_error(anthill, 7);
    }
}