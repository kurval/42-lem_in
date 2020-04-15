/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 19:34:38 by vkurkela          #+#    #+#             */
/*   Updated: 2020/04/15 11:17:00 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"

void update_rev_paths(t_path *path)
{
    t_path      *current;
    t_connect   *temp;
    t_connect   *prev;
    int         i;

    current = path;
    while (current)
    {
        if (current->type != -1)
        {
            temp = current->route->next;
            prev = current->route;
            i = 0;
            while(temp)
            {
                i == 0 ? prev->room->prev = NULL : 0;
                temp->room->prev = prev->room;
                prev = prev->next;
                temp = temp->next;
                i++;
            }
        }
        current = current->next;
    }
}
