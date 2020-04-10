/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 11:34:26 by vkurkela          #+#    #+#             */
/*   Updated: 2020/04/10 13:15:01 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		print_rooms(t_lem_in *anthill)
{
	t_room *current;

	current = anthill->room;
	while (current)
	{
		ft_printf("room %s id %d\n", current->name, current->id);
		current = current->next;
	}
}

void		print_flow(t_lem_in *anthill)
{
	unsigned int i;
	unsigned int j;

	j = 0;
	ft_printf("FLOW CHART\n");
	while (j < anthill->room_count)
	{
		i = 0;
		while (i < anthill->room_count)
		{
			if (anthill->flow[j][i] == 1)
				ft_printf(GREEN "%3d" RESET, anthill->flow[j][i]);
			else if (anthill->flow[j][i] == -1)
				ft_printf(BOLDRED "%3d" RESET, anthill->flow[j][i]);
			else
				ft_printf("%3d", anthill->flow[j][i]);
			i++;
		}
		ft_printf("\n");
		j++;
	}
}

static void	check_flag(char *arg, t_lem_in *anthill)
{
	if (ft_strequ(arg, "-p"))
		anthill->flag = 1;
}
/*
static void	print_rev_names(t_path *path)
{
	t_connect *current;

	current = path->route;
	while (current)
	{
		if (current->room->prev)
			ft_printf("rooms %s prev: %s\n", current->room->name, current->room->prev->name);
		current = current->next;
	}
}
*/
int			main(int arg, char **argc)
{
	t_lem_in	anthill;
	
	init_anthill(&anthill);
	(arg == 2) ? check_flag(argc[1], &anthill) : 0;
	(arg != 1 && !anthill.flag) ? print_error(&anthill, 1) : 0;
	parse_map(&anthill);
	validate_map(&anthill);
	check_short(&anthill);
	solver(&anthill);
	print_map(&anthill);
	anthill.flag ? print_path(&anthill) : 0;
	print_rooms(&anthill);
	print_flow(&anthill);
	exit(0);
	move_ants(&anthill);
	anthill.flag ?\
	ft_printf("\nMoves: %d\n", anthill.moves) : 0;
	free_all(&anthill);
	return (0);
}
