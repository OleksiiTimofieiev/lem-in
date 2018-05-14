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

t_ways	*find_to_add_the_full_path(t_ways **ways, int search)
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

void	ways_len(t_ways **ways)
{
	int				i;
	t_ways			*way_node;
	t_way_option	*w_option;

	way_node = *ways;
	while (way_node)
	{
		i = 0;
		w_option = way_node->o_next;
		while (w_option)
		{
			i++;
			w_option = w_option->next;
		}
		way_node->way_len = i;
		way_node = way_node->next;
	}
}
