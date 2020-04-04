/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 11:34:26 by vkurkela          #+#    #+#             */
/*   Updated: 2020/04/04 14:10:57 by vkurkela         ###   ########.fr       */
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

	ret = 1;
	init_anthill(&anthill);
	if (arg == 2)
		check_flag(argc[1], &anthill);
	if (arg != 1 && !anthill.flag)
		print_error(&anthill, 1);
	parse_map(&anthill);
	validate_map(&anthill);
	check_short(&anthill);
	if (!shortest_path(&anthill) && anthill.quick != 1)
		print_error(&anthill, 9);
	while (ret)
		ret = shortest_path(&anthill);
	print_map(&anthill);
	anthill.flag ? print_path(&anthill) : 0;
	move_ants(&anthill);
	free_all(&anthill);
	return (0);
}
