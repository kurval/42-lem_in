/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 11:34:26 by vkurkela          #+#    #+#             */
/*   Updated: 2020/04/14 16:04:32 by vkurkela         ###   ########.fr       */
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
				ft_printf(GREEN "%3d" EOC, anthill->flow[j][i]);
			else if (anthill->flow[j][i] == -1)
				ft_printf(BOLDRED "%3d" EOC, anthill->flow[j][i]);
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

int			main(int arg, char **argc)
{
	t_lem_in	anthill;
	int			ret;
	
	ret = 0;
	init_anthill(&anthill);
	(arg == 2) ? check_flag(argc[1], &anthill) : 0;
	(arg != 1 && !anthill.flag) ? print_error(&anthill, 1) : 0;
	parse_map(&anthill);
	validate_map(&anthill);
	ret = solver(&anthill);
	print_info(&anthill, ret);
	ret ? move_ants(&anthill, anthill.paths) : 0;
	!ret ? move_ants(&anthill, anthill.paths2) : 0;
	free_all(&anthill);
	return (0);
}
