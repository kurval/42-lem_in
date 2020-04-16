/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 10:50:09 by vkurkela          #+#    #+#             */
/*   Updated: 2020/04/16 21:38:47 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	move(t_lem_in *anthill, t_room *tmp, t_path *path)
{
	int	nbr;

	nbr = path->nb;
	if (path->nb >= 5)
		nbr = path->nb % 5;
	if (!anthill->flag && anthill->print)
		print_standard(tmp);
	else if (anthill->print)
	{
		nbr == 0 ? ft_printf(BOLDBLUE "L%ld-%s " EOC,\
		tmp->ant_here->name, tmp->name) : 0;
		nbr == 1 ? ft_printf(WHT "L%ld-%s " EOC,\
		tmp->ant_here->name, tmp->name) : 0;
		nbr == 2 ? ft_printf(BOLDCYAN "L%ld-%s " EOC,\
		tmp->ant_here->name, tmp->name) : 0;
		nbr == 3 ? ft_printf(BOLDMAGENTA "L%ld-%s " EOC,\
		tmp->ant_here->name, tmp->name) : 0;
		nbr == 4 ? ft_printf(BOLDYELLOW "L%ld-%s " EOC,\
		tmp->ant_here->name, tmp->name) : 0;
	}
	if (tmp == anthill->end)
		anthill->finish++;
}

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
	t_path *s_b;

	s_b = !anthill->extra ? anthill->paths :\
	anthill->paths2;
	tmp = anthill->start;
	if (path->len <= (((anthill->ants + 1) -\
	anthill->start->ant_here->name) * s_b->len))
	{
		if (!tmp->ant_here)
			return ;
		other_room = path->route->room;
		other_room->ant_here = tmp->ant_here;
		tmp->ant_here = tmp->ant_here->next;
		move(anthill, other_room, path);
	}
}

static void	make_move(t_lem_in *anthill, t_path *current_path,\
t_room *tmp, t_path *s_b)
{
	while (current_path && anthill->finish != anthill->ants)
	{
		anthill->end->prev = current_path->second_last;
		if (current_path->type != NEG)
			send_ants(anthill, tmp, current_path);
		if (anthill->start->ant_here && current_path != s_b &&\
		current_path->type != NEG)
			other_path(anthill, tmp, current_path);
		current_path = current_path->next;
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
