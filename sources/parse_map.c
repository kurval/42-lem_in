/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 11:09:19 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/12 20:53:53 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void check_ants(t_lem_in **ant_hill, char *line)
{
    if (ft_atoi_err(line))
    {
        (*ant_hill)->ants = ft_atoi(line);
        (*ant_hill)->p = ROOMS;
    }
    else
        (*ant_hill)->errnbr = 8;
}

int         parse_map(t_lem_in *ant_hill)
{
    int		ret;
	char	*line;

    ant_hill->p = 0;
    ant_hill->errnbr = 0;
	while ((ret = get_next_line(0, &line)) > 0 && ant_hill->errnbr == 0)
	{
        if (!ant_hill->p)
		    check_ants(&ant_hill, line);
        else if (line[0] == '#' && line[1] != '#')
            continue;
        else if (line[0] == '#' && line[1] == '#')
            check_start_end(ant_hill, line);
        else if (ant_hill->p == ROOMS || ant_hill->p == START || ant_hill->p == END)
            check_rooms(&ant_hill, line);
        else if (ant_hill->p == LINKS)
            check_links(&ant_hill, line);
        free(line);
	}
	if (ret == -1)
		return (0);
	return (1);
}