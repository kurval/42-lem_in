/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 16:55:50 by vkurkela          #+#    #+#             */
/*   Updated: 2020/04/17 11:44:27 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"

void		print_rev_names(t_path *path)
{
	t_connect *current;

	current = path->route;
	while (current)
	{
		if (current->room->prev)
			ft_printf("rooms %s prev: %s\n", current->room->name,\
			current->room->prev->name);
		current = current->next;
	}
}

static void	print_header(t_path *path, int nb)
{
	int	nbr;

	nbr = path->nb;
	if (nbr >= 5)
		nbr = nbr % 5;
	nbr == 0 ? ft_printf(BOLDBLUE "PATH %d:\n" EOC, nb) : 0;
	nbr == 1 ? ft_printf(WHT "PATH %d:\n" EOC, nb) : 0;
	nbr == 2 ? ft_printf(BOLDCYAN "PATH %d:\n" EOC, nb) : 0;
	nbr == 3 ? ft_printf(BOLDMAGENTA "PATH %d:\n" EOC, nb) : 0;
	nbr == 4 ? ft_printf(BOLDYELLOW "PATH %d:\n" EOC, nb) : 0;
}

static void	print_rooms(t_lem_in *anthill, t_path *path, int nb)
{
	t_connect	*current;

	current = path->route;
	print_header(path, nb);
	path->nb != 1 ?\
	ft_printf(WHT "%s" EOC, anthill->start->name) : 0;
	path->nb != 1 ?\
	ft_printf(GREEN " => " EOC, anthill->start->name) : 0;
	while (current)
	{
		ft_printf(WHT "%s" EOC, current->room->name);
		(current->room != anthill->end) ? ft_printf(GREEN " => " EOC) : 0;
		current = current->next;
	}
	ft_printf("\n");
}

void		print_path(t_lem_in *anthill, t_path *root)
{
	t_path		*path;
	int			nb;

	path = root;
	nb = 1;
	while (path)
	{
		if (path->type != -1)
			print_rooms(anthill, path, nb);
		nb++;
		path = path->next;
	}
	ft_printf("\n");
}

void		print_anthill(t_lem_in *anthill, int ret)
{
	print_map(anthill);
	anthill->flag && ret ? print_path(anthill, anthill->paths) : 0;
	anthill->flag && !ret ? print_path(anthill, anthill->paths2) : 0;
}
