/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 11:12:08 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/12 20:10:37 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void    print_error(int errno, t_lem_in *ant_hill)
{
    errno == 1 ? ERROR(MESSAGE1) : 0;
    errno == 2 ? ERROR(MESSAGE2) : 0;
    errno == 3 ? ERROR(MESSAGE3) : 0;
    errno == 4 ? ERROR(MESSAGE4) : 0;
    errno == 5 ? ERROR(MESSAGE5) : 0;
    errno == 6 ? ERROR(MESSAGE6) : 0;
    errno == 7 ? ERROR(MESSAGE7) : 0;
    free_links((*ant_hill).link);
    free_rooms((*ant_hill).room);
    exit(0);
}