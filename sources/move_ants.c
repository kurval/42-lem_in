/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 10:50:09 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/30 21:35:25 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void move(t_lem_in *anthill, t_room *tmp)
{
	MOVE(tmp->ant_here->name, tmp->name);
	if (tmp == anthill->end)
		anthill->finish++;
}

static void send_ants(t_lem_in *anthill, t_room *tmp)
{
	tmp = anthill->end;
	while (tmp)
	{
		if (tmp->prev && tmp->prev->ant_here && !tmp->ant_here) //next room is empty
		{
			tmp->ant_here = tmp->prev->ant_here; //swithches ant from previous room to point current room
			move(anthill, tmp); //print this move
		}
		else if (tmp->ant_here) //move next ant at the current room
		{
			//ft_printf("loop room %s ant L%ld", tmp->name, tmp->ant_here->name);
			if (!tmp->prev && tmp != anthill->start)
				tmp->ant_here = NULL;
			else if (tmp->prev)
				tmp->ant_here = tmp->prev->ant_here;
			else 
				tmp->ant_here = tmp->ant_here->next;
			//ft_printf("loop tmp ant L%ld\n", tmp->ant_here->name);
			if (tmp != anthill->start && tmp->ant_here) //if current is not start AND there is ants left
				move(anthill, tmp);
		}
		tmp = tmp->prev;
	}
}

static void	other_path(t_lem_in *anthill, t_room *tmp, t_path *path)
{
	t_room *other_room;

	tmp = anthill->start;
	if (!tmp->ant_here)
		return ;
	other_room = path->route->room;
	other_room->ant_here = tmp->ant_here;
	tmp->ant_here = tmp->ant_here->next;
	move(anthill, other_room);
}

static	int count_paths(t_lem_in *anthill)
{
	t_path	*current;
	int		nb;

	current = anthill->paths;
	nb = 0;
	while (current)
	{
		nb++;
		current = current->next;
	}
	return (nb);
}

void	move_ants(t_lem_in *anthill)
{
	t_room	*tmp;
	t_path	*shortest_path;
	int		nb_paths;
	int		i;

    tmp = NULL;
	i = 0;
	nb_paths = count_paths(anthill);
    anthill->start->ant_here = anthill->ant_lst;
    while (anthill->finish != anthill->ants)
	{
		shortest_path = anthill->paths;
		while (shortest_path && anthill->finish != anthill->ants)
		{
			anthill->end->prev = shortest_path->second_last;
			send_ants(anthill, tmp);
			i++;
			if (anthill->start->ant_here && nb_paths == i)
			{
				other_path(anthill, tmp, shortest_path);
				break ;
			}
			shortest_path = shortest_path->next;
		}
		ft_printf("\n");
	}
}