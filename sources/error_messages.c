/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 11:12:08 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/17 23:12:50 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void    print_error(int errno, t_lem_in *anthill)
{
    ft_printf("errno is %d\n", errno);
    errno == 1 ? ERROR(anthill->line, MESSAGE1) : 0;
    errno == 2 ? ERROR(anthill->line, MESSAGE2) : 0;
    errno == 3 ? ERROR(anthill->line, MESSAGE3) : 0;
    errno == 4 ? ERROR(anthill->line, MESSAGE4) : 0;
    errno == 5 ? ERROR(anthill->line, MESSAGE5) : 0;
    errno == 6 ? ERROR(anthill->line, MESSAGE6) : 0;
    errno == 7 ? ERROR(anthill->line, MESSAGE7) : 0;
    errno == 8 ? ERROR(anthill->line, MESSAGE8) : 0;
    errno == 10 ? ERROR(anthill->line, MESSAGE10) : 0;
    errno == 11 ? ERROR(anthill->line, MESSAGE11) : 0;
    errno == 12 ? ERROR(anthill->line, MESSAGE12) : 0;
    errno == 13 ? ERROR(anthill->line, MESSAGE13) : 0;
    errno == 14 ? ERROR(anthill->line, MESSAGE14) : 0;
    errno == 15 ? ERROR(anthill->line, MESSAGE15) : 0;
    free_all(anthill);
    exit(0);
}