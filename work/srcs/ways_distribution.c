/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ways_distribution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 11:15:31 by otimofie          #+#    #+#             */
/*   Updated: 2018/05/15 11:15:34 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_quantity_of_ways(t_ways *ways)
{
	int i;

	i = 0;
	while (ways)
	{
		i++;
		ways = ways->next;
	}
	return (i);
}

int		shortest_way_id(t_ways *ways)
{
	int id;
	int min;

	id = ways->way_id;
	min = ways->way_len;
	while (ways)
	{
		if (ways->way_len < min)
		{
			min = ways->way_ants;
			id = ways->way_id;
		}
		ways = ways->next;
	}
	return (id);
}

void	ft_apply_shortest(t_ways *ways, int quantity, int id)
{
	while (ways)
	{
		if (ways->way_id == id)
			ways->way_ants = quantity;
		ways = ways->next;
	}
}

int		b_detect(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (ft_strequ(argv[i], "-ways_select"))
			return (1);
		i++;
	}
	return (0);
}

void	d1(t_data data, t_ways *ways, int argc, char **argv)
{
	int	ways_amount;
	int *len;
	int	*way;

	if (ft_quantity_of_ways(ways) == q_of_act_w(ways) && !b_detect(argc, argv))
	{
		ft_apply_shortest(ways, data.quantity_of_ants, shortest_way_id(ways));
		return ;
	}
	ways_amount = q_of_act_w(ways);
	len = (int *)malloc(sizeof(int) * ways_amount);
	ft_init_len(len, ways);
	way = (int *)malloc(sizeof(int) * ways_amount);
	ft_init_way(way, ways_amount);
	ways_1(data, ways, way, len);
	ft_update_the_ways_data(ways, way);
	free(len);
	free(way);
}
