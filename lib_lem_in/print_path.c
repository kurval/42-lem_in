/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 16:55:50 by vkurkela          #+#    #+#             */
/*   Updated: 2020/04/15 20:55:26 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"

void	print_rev_names(t_path *path)
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

void		print_header(int nbr)
{
	if (nbr >= 5)
		nbr = nbr % 5;
	nbr == 0 ? ft_printf(BOLDBLUE "PATH %d:\n" EOC, nbr) : 0;
	nbr == 1 ? ft_printf(WHT "PATH %d:\n" EOC, nbr) : 0;
	nbr == 2 ? ft_printf(BOLDCYAN "PATH %d:\n" EOC, nbr) : 0;
	nbr == 3 ? ft_printf(BOLDMAGENTA "PATH %d:\n" EOC, nbr) : 0;
	nbr == 4 ? ft_printf(BOLDYELLOW "PATH %d:\n" EOC, nbr) : 0;
}

void		print_path(t_lem_in *anthill, t_path *root)
{
	t_path		*path;
	t_connect	*current;
	int			nbr;

	path = root;
	nbr = path ? 1 : 0;
	while (path)
	{
		current = path->route;
		print_header(nbr);
		nbr != 1 ?\
		ft_printf(WHT "%s" EOC, anthill->start->name) : 0;
		nbr != 1 ?\
		ft_printf(GREEN " => " EOC, anthill->start->name) : 0;
		while (current)
		{
			ft_printf(WHT "%s" EOC, current->room->name);
			(current->room != anthill->end) ? ft_printf(GREEN " => " EOC) : 0;
			current = current->next;
		}
		nbr++;
		ft_printf("\n");
		path = path->next;
	}
	ft_printf("\n");
}

void	print_info(t_lem_in *anthill, int ret)
{
	print_map(anthill);
	anthill->flag && ret ? print_path(anthill, anthill->paths) : 0;
	anthill->flag && !ret ? print_path(anthill, anthill->paths2) : 0;
}
