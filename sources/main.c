/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 11:34:26 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/27 14:55:20 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int main(int arg, char **argc)
{
    t_lem_in    anthill;

    argc = NULL;
    init_anthill(&anthill);
    if (arg != 1)
        print_error(&anthill, 7);
    parse_map(&anthill);
    validate_map(&anthill);
    print_map(&anthill);
    check_short(&anthill);
    if (!solver(&anthill) && anthill.quick != 1)
        print_error(&anthill, 9);
    while (solver(&anthill));
    print_path(&anthill);
    free_all(&anthill);
    return (0);
}