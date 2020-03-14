/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 13:43:51 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/14 16:59:14 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int validate_map(t_lem_in *anthill)
{
    if (!anthill->start || !anthill->end || !anthill->end)
    {
        !anthill->start && !anthill->errnbr ? anthill->errnbr = 13 : 0;
        !anthill->end && !anthill->errnbr ? anthill->errnbr = 14 : 0;
        !anthill->end && !anthill->errnbr ? anthill->errnbr = 12 : 0;
        return (0);
    }
    return (1);
}