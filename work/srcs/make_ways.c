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

t_ways			*build_ways_node(int i)
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

t_way_option	*build_option_node(char *str)
{
	t_way_option *tmp;

	tmp = (t_way_option*)malloc(sizeof(t_way_option));
	tmp->node_id = ft_strdup(str);
	tmp->next = NULL;
	return (tmp);
}

void			ways_node_constructor(t_ways **ways, int way_id)
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

void			construct(t_way *way, t_ways **ways, t_data data, int *way_id)
{
	t_ways			*o_ways;
	t_way_option	*w_option;

	if (ft_strequ(way->way_room, data.start))
	{
		ways_node_constructor(ways, ++(*way_id));
		o_ways = find_to_add_the_full_path(ways, *way_id);
		if (!(o_ways->o_next))
			o_ways->o_next = build_option_node(way->way_room);
	}
	else
	{
		o_ways = find_to_add_the_full_path(ways, *way_id);
		if (o_ways->o_next)
		{
			w_option = o_ways->o_next;
			while (w_option->next)
				w_option = w_option->next;
			w_option->next = build_option_node(way->way_room);
		}
	}
}

void			multiple_ways(t_way *way, t_ways **ways, t_data data)
{
	int way_id;

	way_id = 0;
	while (way)
	{
		construct(way, ways, data, &way_id);
		way = way->next;
	}
	ways_len(ways);
	// add func to quantity of ants for the way;
}
