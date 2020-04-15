/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 11:09:19 by vkurkela          #+#    #+#             */
/*   Updated: 2020/04/15 16:07:45 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	check_ants(t_lem_in **anthill, char *line)
{
	if (!ft_atoi_err(line) || ft_atoi(line) == 0)
	{
		(*anthill)->errnbr = 8;
		return ;
	}
	else
	{
		(*anthill)->ants = ft_atoi(line);
		if (!add_ants(&(*anthill)->ant_lst, (*anthill)->ants))
		{
			(*anthill)->errnbr = 7;
			return ;
		}
		(*anthill)->section = ROOMS;
	}
}

int			parse_map(t_lem_in *anthill)
{
	int		ret;
	char	*line;

	while ((ret = get_next_line(0, &line)) > 0 && anthill->errnbr == 0)
	{
		if (line[0] == '#' && line[1] != '#')
			;
		else if (!anthill->section && line[0] != '#')
			check_ants(&anthill, line);
		else if (line[0] == '#' && line[1] == '#')
			check_start_end(anthill, line);
		else if (anthill->section == ROOMS ||\
			anthill->section == START || anthill->section == END)
			check_rooms(&anthill, line);
		else if (anthill->section == LINKS)
			check_links(&anthill, line);
		if (!anthill->errnbr)
			add_to_map(&(*anthill).map, line);
		anthill->line += 1;
		free(line);
	}
	free(line);
	ret == -1 ? print_error(anthill, 16) : 0;
	return (1);
}
