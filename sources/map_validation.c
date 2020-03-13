/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 13:43:51 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/13 13:59:50 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int validate_map(t_lem_in *ant_hill)
{
    !ant_hill->link ? ant_hill->errnbr = 12 : 0;
    !ant_hill->start ? ant_hill->errnbr = 13 : 0;
    !ant_hill->end ? ant_hill->errnbr = 14 : 0;
    return (0);
}