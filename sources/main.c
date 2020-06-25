/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 11:34:26 by vkurkela          #+#    #+#             */
/*   Updated: 2020/06/25 18:28:13 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	init_flags(t_lem_in *anthill)
{
	anthill->flags->flag = 0;
	anthill->flags->flag_err = 0;
	anthill->flags->flag_col = 0;
}

static int	check_flag(char *arg, t_lem_in *anthill)
{
	int ret;

	ret = 1;
	init_flags(anthill);
	if (ft_strequ(arg, "-p"))
		anthill->flags->flag = 1;
	else if (ft_strequ(arg, "-e"))
		anthill->flags->flag_err = 1;
	else if (ft_strequ(arg, "-c"))
		anthill->flags->flag_col = 1;
	else if (ft_strequ(arg, "-pc") || ft_strequ(arg, "-cp"))
	{
		anthill->flags->flag = 1;
		anthill->flags->flag_col = 1;
	}
	else
		ret = 0;
	return (ret);
}

int			main(int arg, char **argc)
{
	t_lem_in	anthill;
	int			ret;

	ret = 0;
	init_anthill(&anthill);
	if (!(anthill.flags = (t_flags*)malloc(sizeof(t_flags))))
		print_error(&anthill, 7);
	if (arg != 1)
		(!check_flag(argc[1], &anthill)) ?\
		print_error(&anthill, 1) : 0;
	parse_map(&anthill);
	validate_map(&anthill);
	ret = solver(&anthill);
	print_anthill(&anthill, ret);
	ret ? move_ants(&anthill, anthill.paths) : 0;
	!ret ? move_ants(&anthill, anthill.paths2) : 0;
	free_all(&anthill);
	return (0);
}
