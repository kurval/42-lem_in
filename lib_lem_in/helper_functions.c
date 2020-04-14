/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 15:57:24 by vkurkela          #+#    #+#             */
/*   Updated: 2020/04/14 18:00:33 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"

void	count_rooms(t_lem_in *anthill)
{
	t_room *current;

	current = anthill->room;
	while (current)
	{
		current = current->next;
		anthill->room_count += 1;
	}
}

void	free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_paths(t_path *root)
{
	t_path *temp;

	temp = NULL;
	if (!root)
		return ;
	while (root)
	{
		temp = root;
		root = root->next;
		free_connections(temp->route);
		free(temp);
	}
}

void	print_error(t_lem_in *anthill, int errnbr)
{
	ft_printf(BOLDRED "error " EOC);
	errnbr == 1 ? ft_printf("%s\n", MSG1) : 0;
	errnbr == 2 ? ft_printf(ERR, anthill->line, MSG2) : 0;
	errnbr == 3 ? ft_printf(ERR, anthill->line, MSG3) : 0;
	errnbr == 4 ? ft_printf(ERR, anthill->line, MSG4) : 0;
	errnbr == 5 ? ft_printf(ERR, anthill->line, MSG5) : 0;
	errnbr == 6 ? ft_printf(ERR, anthill->line, MSG6) : 0;
	errnbr == 7 ? ft_printf("%s\n", MSG7) : 0;
	errnbr == 8 ? ft_printf(ERR, anthill->line, MSG8) : 0;
	errnbr == 9 ? ft_printf("%s\n", MSG9) : 0;
	errnbr == 10 ? ft_printf(ERR, anthill->line, MSG10) : 0;
	errnbr == 11 ? ft_printf(ERR, anthill->line, MSG11) : 0;
	errnbr == 12 ? ft_printf("%s\n", MSG12) : 0;
	errnbr == 13 ? ft_printf("%s\n", MSG13) : 0;
	errnbr == 14 ? ft_printf("%s\n", MSG14) : 0;
	errnbr == 16 ? ft_printf(ERR, anthill->line, MSG16) : 0;
	errnbr == 17 ? ft_printf(ERR, anthill->line, MSG17) : 0;
	free_all(anthill);
	exit(0);
}

int		path_len(t_path *root)
{
	t_connect	*tmp;
	int			len;

	len = 0;
	if (!root->route)
		return (0);
	tmp = root->route;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}
