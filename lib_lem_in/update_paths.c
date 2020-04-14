/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 19:34:38 by vkurkela          #+#    #+#             */
/*   Updated: 2020/04/14 20:54:30 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"

void update_rev_paths(t_path *path)
{
    t_path      *current;
    t_connect   *temp;
    t_connect   *prev;

    current = path;
    while (current)
    {
        if (current->type != -1)
        {
            temp = current->route->next;
            prev = current->route;
            while(temp)
            {
                if (!temp->room->second)
                    temp->room->prev = prev->room;
                prev = prev->next;
                temp = temp->next;
            }
        }
        current = current->next;
    }
}
