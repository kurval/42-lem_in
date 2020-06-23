/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 18:40:27 by vkurkela          #+#    #+#             */
/*   Updated: 2020/06/23 17:39:20 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	move(t_lem_in *anthill, t_room *tmp, t_path *path)
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
