/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 10:50:09 by vkurkela          #+#    #+#             */
/*   Updated: 2020/06/17 10:58:16 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
 ** Moving each ant of current path one room forward.
*/

static void	send_ants(t_lem_in *anthill, t_room *tmp, t_path *path)
{
	tmp = anthill->end;
	while (tmp)
	{
		if (tmp->prev && tmp->prev->ant_here && !tmp->ant_here)
		{
			tmp->ant_here = tmp->prev->ant_here;
			move(anthill, tmp, path);
		}
		else if (tmp->ant_here)
		{
			if (!tmp->prev && tmp != anthill->start)
				tmp->ant_here = NULL;
			else if (tmp->prev)
				tmp->ant_here = tmp->prev->ant_here;
			else
				tmp->ant_here = tmp->ant_here->next;
			if (tmp != anthill->start && tmp->ant_here)
				move(anthill, tmp, path);
		}
		tmp = tmp->prev;
	}
}

static void	other_path(t_lem_in *anthill, t_room *tmp, t_path *path)
{
	t_room *other_room;
	t_path *s_p;

	s_p = !anthill->extra ? anthill->paths :\
	anthill->paths2;
	tmp = anthill->start;
	if (!tmp->ant_here)
		return ;
	other_room = path->route->room;
	other_room->ant_here = tmp->ant_here;
	tmp->ant_here = tmp->ant_here->next;
	path->ant_s--;
	move(anthill, other_room, path);
}

static void	make_move(t_lem_in *anthill, t_path *current_path,\
t_room *tmp, t_path *s_p)
{
	while (current_path && anthill->finish != anthill->ants)
	{
		anthill->end->prev = current_path->second_last;
		if (current_path->type != NEG)
			send_ants(anthill, tmp, current_path);
		if (anthill->start->ant_here && current_path != s_p &&\
		current_path->type != NEG && current_path->ant_s)
			other_path(anthill, tmp, current_path);
		current_path = current_path->next;
	}
}

static void	div_ants(t_lem_in *anthill, t_path *s_p)
{
	int		i;
	int		cost;
	t_path	*current_path;
	t_path	*best_path;

	i = 0;
	s_p->ant_s = 0;
	while (i < anthill->ants)
	{
		current_path = s_p;
		while (current_path && i < anthill->ants)
		{
			if (current_path->type != NEG && cost >\
			current_path->len + current_path->ant_s && current_path != s_p)
				best_path = current_path;
			else
				best_path = s_p;
			best_path->ant_s++;
			cost = best_path->ant_s + best_path->len;
			current_path = best_path->next;
			i++;
		}
	}
}

/*
 ** Moving ants one path at a time
 ** while each ant have reached end node.
*/

int			move_ants(t_lem_in *anthill, t_path *path)
{
	t_room	*tmp;
	t_path	*current_path;

	tmp = NULL;
	anthill->moves = 0;
	anthill->finish = 0;
	anthill->start->ant_here = anthill->ant_lst;
	div_ants(anthill, path);
	while (anthill->finish != anthill->ants)
	{
		current_path = path;
		make_move(anthill, current_path, tmp, path);
		anthill->moves++;
		anthill->print ? ft_printf("\n") : 0;
	}
	anthill->flag && anthill->print ?\
	ft_printf(WHT "\nMoves: %d\n" EOC, anthill->moves) : 0;
	return (anthill->moves);
}
