/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 11:34:26 by vkurkela          #+#    #+#             */
/*   Updated: 2020/04/16 21:14:03 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

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
	print_anthill(&anthill, ret);
	ret ? move_ants(&anthill, anthill.paths) : 0;
	!ret ? move_ants(&anthill, anthill.paths2) : 0;
	free_all(&anthill);
	return (0);
}
