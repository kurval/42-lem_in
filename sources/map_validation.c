/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 13:43:51 by vkurkela          #+#    #+#             */
/*   Updated: 2020/06/25 18:45:44 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	validate_map(t_lem_in *anthill)
{
	if (!anthill->start || !anthill->end || !anthill->link)
	{
		!anthill->link && !anthill->errnbr ? anthill->errnbr = 12 : 0;
		!anthill->start && !anthill->errnbr ? anthill->errnbr = 13 : 0;
		!anthill->end && !anthill->errnbr ? anthill->errnbr = 14 : 0;
		print_error(anthill, anthill->errnbr);
	}
	count_rooms(anthill);
	create_hashtable(anthill);
	create_connections(anthill);
	create_flow_chart(anthill);
}
