/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 19:34:38 by vkurkela          #+#    #+#             */
/*   Updated: 2020/04/13 20:51:35 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"

static void delete_paths(t_path **root, int path_type)
{
    t_path *temp = *root;
    t_path *prev = NULL;
  
    while (temp != NULL && temp->type != path_type) 
    { 
        *root = temp->next;
        free(temp);
        temp = *root;
    }
    while (temp != NULL)
    { 
        while (temp != NULL && temp->type == path_type) 
        { 
            prev = temp;
            temp = temp->next;
        } 
        if (temp == NULL)
            return ;
        prev->next = temp->next;
        free(temp);
        temp = prev->next; 
    }
}

static int  add_start(t_path *root, t_lem_in *anthill)
{
    if (!(add_connect(&root->route, anthill->start)))
        return (0);
    root->route->next->room->prev = anthill->start;
    return (1);
}

static void update_rev_path(t_lem_in *anthill)
{
    t_path *current;
    t_connect *temp;
    t_connect *prev;

    current = anthill->paths;
    while (current)
    {
        temp = current->route->next;
        prev = current->route;
        while(temp)
        {
            temp->room->prev = prev->room;
            prev = prev->next;
            temp = temp->next;
        }
        current = current->next;
    }
}

void    update_paths(t_lem_in *anthill, int type)
{
    delete_paths(&anthill->paths, type);
    if (type == 3)
    {
        if(!(add_start(anthill->paths, anthill)))
            print_error(anthill, 7);
    }
    update_rev_path(anthill);
}
