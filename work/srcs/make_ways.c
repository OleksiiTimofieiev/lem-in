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

void	construct_final_ways(t_way *way, t_ways **ways, t_data data, int *way_id)
{
	t_ways *o_ways;

	if (ft_strequ(way->way_room, data.start))
	{
		ways_node_constructor(ways, ++(*way_id));
		// ft_printf("iter->%d\n", *way_id);
		o_ways = find_to_add_the_full_path(ways, *way_id);
		if (!o_ways->o_next)
			ft_printf("%s\n", "nope");

		// ft_printf("%d\n", o_ways->way_id);

	}
	//add to o_ways too;
	else
	{

	}
	//add to o_ways for the current way;

}

void	multiple_ways(t_way *way, t_ways **ways, t_data data)
{
	int way_id;

	way_id = 0;
	while (way)
	{
		construct_final_ways(way, ways, data, &way_id);
		way = way->next;
	}
	// ft_printf("%d\n", find_to_add_the_full_path(ways, 1)->way_id);
	// ft_printf("%d\n", find_to_add_the_full_path(ways, 2)->way_id);

}
