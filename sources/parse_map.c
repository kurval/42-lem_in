/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 11:09:19 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/11 16:24:01 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void check_ants(t_lem_in **ant_hill, char *line, int *nbr)
{
    if (ft_atoi_err(line))
    {
        (*ant_hill)->ants = ft_atoi(line);
        *nbr = ROOMS;
    }
    else
        exit(0);
}

int         parse_map(t_lem_in *ant_hill)
{
    int		ret;
	char	*line;
    int     nbr;

    nbr = 0;
	while ((ret = get_next_line(0, &line)) > 0)
	{
        if (!nbr)
		    check_ants(&ant_hill, line, &nbr);
        else if (line[0] == '#' && line[1] != '#')
            continue;
        else if (line[0] == '#' && line[1] == '#')
            check_start_end(line, &nbr);
        else if (nbr == ROOMS || nbr == START || nbr == END)
            check_rooms(&ant_hill, line, &nbr);
        //else if (nbr == LINKS)
            //check_links(&ant_hill, line);
        free(line);
	}
	if (ret == -1)
		return (0);
	return (1);
}