/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 11:12:08 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/18 21:09:52 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void    print_error(t_lem_in *anthill)
{
    ft_printf("anthill->errnbr is %d\n", anthill->errnbr);
    anthill->errnbr == 1 ? ERROR(anthill->line, MESSAGE1) : 0;
    anthill->errnbr == 2 ? ERROR(anthill->line, MESSAGE2) : 0;
    anthill->errnbr == 3 ? ERROR(anthill->line, MESSAGE3) : 0;
    anthill->errnbr == 4 ? ERROR(anthill->line, MESSAGE4) : 0;
    anthill->errnbr == 5 ? ERROR(anthill->line, MESSAGE5) : 0;
    anthill->errnbr == 6 ? ERROR(anthill->line, MESSAGE6) : 0;
    anthill->errnbr == 7 ? ERROR(anthill->line, MESSAGE7) : 0;
    anthill->errnbr == 8 ? ERROR(anthill->line, MESSAGE8) : 0;
    anthill->errnbr == 10 ? ERROR(anthill->line, MESSAGE10) : 0;
    anthill->errnbr == 11 ? ERROR(anthill->line, MESSAGE11) : 0;
    anthill->errnbr == 12 ? ERROR(anthill->line, MESSAGE12) : 0;
    anthill->errnbr == 13 ? ERROR(anthill->line, MESSAGE13) : 0;
    anthill->errnbr == 14 ? ERROR(anthill->line, MESSAGE14) : 0;
    anthill->errnbr == 15 ? ERROR(anthill->line, MESSAGE15) : 0;
    free_all(anthill);
    exit(0);
}