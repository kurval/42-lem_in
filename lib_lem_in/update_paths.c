/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 19:34:38 by vkurkela          #+#    #+#             */
/*   Updated: 2020/04/12 21:19:03 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"

void    update_paths(t_path **root, int path_type)
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
            return; 
        prev->next = temp->next; 
        free(temp);
        temp = prev->next; 
    }
}