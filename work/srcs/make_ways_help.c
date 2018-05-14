/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_ways_help.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 10:49:52 by otimofie          #+#    #+#             */
/*   Updated: 2018/05/14 10:49:53 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ways			*find_to_add_the_full_path(t_ways **ways, int search)
{
	t_ways *tmp;

	tmp = *ways;
	while (tmp)
	{
		if (tmp->way_id == search)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

// add func of way len;
