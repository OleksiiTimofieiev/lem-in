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

void	ways_node_constructor(t_ways **ways, int i)
{
	t_ways *tmp;

	if (!*ways)
		*ways = build_ways_node(i);
	else
	{
		tmp = *ways;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = build_ways_node(i);
	}
}

void	construct_final_ways(t_way *way, t_ways **ways, t_data data, int *i)
{
	if (ft_strequ(way->way_room, data.start))
	{
		ways_node_constructor(ways, (*i)++);
	}
}

void	multiple_ways(t_way *way, t_ways **ways, t_data data)
{
	int i;

	i = 1;
	while (way)
	{
		construct_final_ways(way, ways, data, &i);
		way = way->next;
	}
}
