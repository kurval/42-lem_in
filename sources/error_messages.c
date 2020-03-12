/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 11:12:08 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/12 14:15:09 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void    print_error(int errno)
{
    errno == 1 ? ft_printf("Error: usage: ./lem-in < [source file]\n") : 0;
    errno == 2 ? ft_printf("Error: room name is invalid\n") : 0;
    errno == 3 ? ft_printf("Error: room format: (room x y)\n") : 0;
    errno == 4 ? ft_printf("Error: rooms coordinate is invalid\n") : 0;
    errno == 5 ? ft_printf("Error: link format: (room-room)\n") : 0;
    errno == 6 ? ft_printf("Error: invalid room name in link\n") : 0;
    exit(0);
}