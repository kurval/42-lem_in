/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 11:09:19 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/11 15:16:17 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void check_rooms(t_lem_in **ant_hill, char *line, int *nbr)
{
    char    **tab;
    int     i;

    i = 0;
    if (line[0] == 'L')
        exit(0);
    tab = ft_strsplit(line, ' ');
    while (tab[i])
        i++;
    if (i > 3 || !ft_atoi_err(tab[1]) || !ft_atoi_err(tab[2]))
        exit(0);
    else if (i == 3)
    {
        add_room(&(*ant_hill)->room, tab[0], ft_atoi(tab[1]), ft_atoi(tab[2]));
        *nbr == 2 ? (*ant_hill)->start = (*ant_hill)->room : 0;
        *nbr == 3 ? (*ant_hill)->end= (*ant_hill)->room : 0;
        *nbr = 1;
    }
    else
        *nbr = 4;
}

static void check_ants(t_lem_in **ant_hill, char *line, int *nbr)
{
    if (ft_atoi_err(line))
    {
        (*ant_hill)->ants = ft_atoi(line);
        *nbr = 1;
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
        else if (nbr == 1 || nbr == 2 || nbr == 3)
            check_rooms(&ant_hill, line, &nbr);
        //check_links(&ant_hill, line);
        free(line);
	}
	if (ret == -1)
		return (0);
	return (1);
}