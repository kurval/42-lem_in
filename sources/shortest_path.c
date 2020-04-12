/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortest_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 12:29:54 by vkurkela          #+#    #+#             */
/*   Updated: 2020/04/12 16:18:12 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void		exit_search(t_lem_in *anthill, t_room **array)
{
	reset_checked_rooms(anthill);
	free(array);
}

int				shortest_path(t_lem_in *anthill)
{
	t_room			**array;
	t_path			*new_path;

	anthill->que = NULL;
	new_path = add_path(&anthill->paths);
	array = (t_room **)malloc(sizeof(t_room*) * 2);
	(!new_path || !array) ? print_error(anthill, 7) : 0;
	array[0] = anthill->start;
	array[1] = NULL;
	if (!check_start_flow(anthill) || !find_path(anthill, array, new_path))
	{
		exit_search(anthill, array);
		del_last(&anthill->paths);
		return (0);
	}
	link_path(anthill, anthill->que, new_path);
	new_path->len = path_len(new_path);
	new_path->nb = anthill->nb_paths++;
	(new_path->nb != 1) ? del_start(&new_path) : 0;
	exit_search(anthill, array);
	return (1);
}

void	solver(t_lem_in *anthill)
{
	int			ret;

	ret = 1;
	while (ret)
		ret = shortest_path(anthill);
	(!anthill->paths) ? print_error(anthill, 9) : 0;
}
