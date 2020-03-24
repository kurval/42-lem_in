/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 11:34:26 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/24 13:41:11 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	print_path(t_lem_in *lem_in)
{
	t_room	*tmp;

	tmp = lem_in->end;
	while (tmp && tmp->path_prev && tmp->path_prev != lem_in->start)
	{
		tmp->path_prev->path_next = tmp;
		tmp = tmp->path_prev;
	}
	tmp = lem_in->start;
    ft_printf("Path:\n");
    while (tmp && tmp != lem_in->end)
    {
        ft_printf("%s -> ", tmp->name);
        tmp = tmp->path_next;
    }
    ft_printf("%s\n", lem_in->end->name);
}
/*
static void	print_rooms(t_room *root)
{
	t_room   *current;

    current = root;
    while(current)
    {
        ft_printf("room's %s id %d\n", current->name, current->id);
        current = current->next;
    }
}
*/
void    init_anthill(t_lem_in *anthill)
{
    anthill->ants = 0;
	anthill->room_count = 0;
	anthill->ant_lst = NULL;
	anthill->room = NULL;
	anthill->link = NULL;
    anthill->start = NULL;
	anthill->end = NULL;
    anthill->map = NULL;
    anthill->hashtable = NULL;
    anthill->paths = NULL;
	anthill->errnbr = 0;
	anthill->section = 0;
    anthill->line = 0;
    anthill->id = 0;
    anthill->reverse_path = NULL;
}

int main(int arg, char **argc)
{
    t_lem_in    anthill;

    argc = NULL;
    init_anthill(&anthill);
    arg != 1 ? anthill.errnbr = 1 : 0;
    arg != 1 ? print_error(&anthill) : 0;
    parse_map(&anthill);
    validate_map(&anthill);
    print_map(&anthill);
    //print_hashes(&anthill);
    print_connections(anthill.room);
    //print_rooms(anthill.room);
    solve(&anthill);
    print_path(&anthill);
    free_all(&anthill);
    return (0);
}