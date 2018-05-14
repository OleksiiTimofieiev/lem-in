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

void	ways_node_constructor(t_way *way, t_ways **ways, int i)
{
		if (!*ways)
		{
			ft_printf("%s\n", "nope");
			ft_printf("%d\n", i);
		}
		ft_printf("%s\n", way->way_room);
}

void	construct_final_ways(t_way *way, t_ways **ways, t_data data, int *i)
{
	if (ft_strequ(way->way_room, data.start))
	{	
		ways_node_constructor(way, ways, (*i)++);
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
