/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 11:34:26 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/31 18:16:05 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	main(int arg, char **argc)
{
	t_lem_in	anthill;

	init_anthill(&anthill);
	if (arg == 2)
		check_flag(argc[1], &anthill);
	if (arg != 1 && !anthill.flag)
		print_error(&anthill, 1);
	parse_map(&anthill);
	validate_map(&anthill);
	print_map(&anthill);
	check_short(&anthill);
	if (!shortest_path(&anthill) && anthill.quick != 1)
		print_error(&anthill, 9);
	while (shortest_path(&anthill));
	anthill.flag ? print_path(&anthill) : 0;
	move_ants(&anthill);
	free_all(&anthill);
	return (0);
}
