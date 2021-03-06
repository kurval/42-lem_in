/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:53:54 by vkurkela          #+#    #+#             */
/*   Updated: 2019/10/23 14:12:19 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*b;
	int				i;

	b = (unsigned char*)s;
	i = 0;
	while (i < (int)n)
	{
		b[i] = 0;
		i++;
	}
}
