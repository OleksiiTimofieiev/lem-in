/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_ways.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 08:13:54 by otimofie          #+#    #+#             */
/*   Updated: 2018/05/14 08:13:56 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ways	*build_ways_node(int i)
{
	t_ways *tmp;

	tmp = (t_ways*)malloc(sizeof(t_ways));
	tmp->way_id = i;
	tmp->way_len = 0;
	tmp->way_ants = 0;
	tmp->o_next = NULL;
	tmp->next = NULL;
	return (tmp);
}

void	ways_node_constructor(t_ways **ways, int way_id)
{
	t_ways *tmp;

	if (!*ways)
		*ways = build_ways_node(way_id);
	else
	{
		tmp = *ways;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = build_ways_node(way_id);
	}
}

void	construct_final_ways(t_way *way, t_ways **ways, t_data data, int *way_id)
{
	int buf;
	if (ft_strequ(way->way_room, data.start))
		ways_node_constructor(ways, (*way_id)++);
	else
		buf = 0;
}

void	multiple_ways(t_way *way, t_ways **ways, t_data data)
{
	int way_id;

	way_id = 1;
	while (way)
	{
		construct_final_ways(way, ways, data, &way_id);
		way = way->next;
	}
}
