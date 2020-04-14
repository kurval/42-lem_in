/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortest_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 12:29:54 by vkurkela          #+#    #+#             */
/*   Updated: 2020/04/14 17:03:47 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void		save_path(t_lem_in *anthill, t_path *new_path, t_room **array)
{
	link_path(anthill, anthill->que, new_path);
	new_path->len = path_len(new_path);
	new_path->type != NEG ? new_path->nb = ++anthill->nb_paths : 0;
	(new_path->nb != 1) ? del_start(&new_path) : 0;
	reset_checked_rooms(anthill);
	free(array);
}

int				shortest_path(t_lem_in *anthill)
{
	t_room			**array;
	t_path			*new_path;

	anthill->que = NULL;
	new_path =  !anthill->extra ? add_path(&anthill->paths) :\
	add_path(&anthill->paths2);
	array = (t_room **)malloc(sizeof(t_room*) * 2);
	(!new_path || !array) ? print_error(anthill, 7) : 0;
	array[0] = anthill->start;
	array[1] = NULL;
	if (!check_start_flow(anthill) || !find_path(anthill, array, new_path))
	{
		reset_checked_rooms(anthill);
		free(array);
		!anthill->extra ? del_last(&anthill->paths) :\
		del_last(&anthill->paths2);
		return (0);
	}
	save_path(anthill, new_path, array);
	return (1);
}

static int	compare_results(t_lem_in *anthill)
{
	int			moves1;
	int			moves2;
	int			ret;

	ret = 1;
	anthill->print = 0;
	moves1 = move_ants(anthill, anthill->paths);
	anthill->extra = 1;
	anthill->nb_paths = 0;
	check_short(anthill);
	while (ret)
		ret = shortest_path(anthill);
	update_rev_paths(anthill->paths2);
	moves2 = move_ants(anthill, anthill->paths2);
	anthill->print = 1;
	if (moves1 <= moves2)
	{
		anthill->extra = 0;
		update_rev_paths(anthill->paths);
		return (1);
	}
	return (0);
}

int		solver(t_lem_in *anthill)
{
	int	ret;

	ret = 1;
	
	check_short(anthill);
	while (ret)
		ret = shortest_path(anthill);
	(!anthill->paths) ? print_error(anthill, 9) : 0;
	if (check_max_paths(anthill))
		return (1);
	ret = compare_results(anthill);
	ft_printf("täällä extra %d\n", anthill->extra);
	return (ret);
}
