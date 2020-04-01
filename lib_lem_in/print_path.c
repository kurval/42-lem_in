/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 16:55:50 by vkurkela          #+#    #+#             */
/*   Updated: 2020/04/01 12:52:51 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"

void		print_header(t_path *path)
{
	int	nbr;

	nbr = path->nb;
	if (path->nb >= 5)
		nbr = path->nb % 5;
	nbr == 0 ? ft_printf(BOLDBLUE "PATH %d:\n" RESET, path->nb) : 0;
	nbr == 1 ? ft_printf(BOLDWHITE "PATH %d:\n" RESET, path->nb) : 0;
	nbr == 2 ? ft_printf(BOLDCYAN "PATH %d:\n" RESET, path->nb) : 0;
	nbr == 3 ? ft_printf(BOLDMAGENTA "PATH %d:\n" RESET, path->nb) : 0;
	nbr == 4 ? ft_printf(BOLDYELLOW "PATH %d:\n" RESET, path->nb) : 0;
}

void		print_path(t_lem_in *anthill)
{
	t_path		*path;
	t_connect	*current;

	path = anthill->paths;
	while (path)
	{
		current = path->route;
		print_header(path);
		path->nb != 1 ?\
		ft_printf(BOLDWHITE "%s" RESET, anthill->start->name) : 0;
		path->nb != 1 ?\
		ft_printf(GREEN " => " RESET, anthill->start->name) : 0;
		while (current)
		{
			ft_printf(BOLDWHITE "%s" RESET, current->room->name);
			if (current->room != anthill->end)
				ft_printf(GREEN " => " RESET);
			current = current->next;
		}
		ft_printf("\n");
		path = path->next;
	}
	ft_printf("\n");
}
