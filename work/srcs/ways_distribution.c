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

int		ft_quantity_of_active_ways(t_ways *ways)
{
	int i;

	i = 0;
	while (ways)
	{
		if (ways->activation == 1)
			i++;
		ways = ways->next;
	}
	return (i);
}

int		ft_find_the_shortest_path(int *arr)
{
	int i;
	int res;
	int min_len;

	i = 0;
	res = 0;
	min_len = arr[0];
	while (arr[i])
	{
		if (arr[i] < min_len)
		{
			min_len = arr[i];
			res = i;
		}
		i++;
	}
	return (res);
}

void	ft_init_len(int *len, t_ways *ways)
{
	int i;

	i = 0;
	while (ways)
	{
		if (ways->activation == 1)
		{
			len[i] = ways->way_len;
			i++;
		}
		ways = ways->next;
	}
}

void	ft_int_way(int *way, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		way[i] = 0;
		i++;

	}
}

void	ft_update_the_ways_data(t_ways *ways, int *way)
{
	int i;

	i = 0;
	while (ways)
	{
		if (ways->activation == 1)
			ways->way_ants = way[i++];
		ways = ways->next;
	}
}

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

int 	ft_find_the_shortest_way_id(t_ways *ways)
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

void	ft_apply_quantity_of_ants_to_the_shortest_one(t_ways *ways, int quantity, int id)
{
	while (ways)
	{
		if (ways->way_id == id)
			ways->way_ants = quantity;
		ways = ways->next;
	}
}


void	ft_ways_distribution(t_data data, t_ways *ways)
{
	int ants_quantity;
	int	ways_amount;
	int *len;
	int	*way;
	int i;
	int j;

	if (ft_quantity_of_ways(ways) == ft_quantity_of_active_ways(ways))
	{
		ft_apply_quantity_of_ants_to_the_shortest_one(ways, data.quantity_of_ants, ft_find_the_shortest_way_id(ways));
		return ;
	}

	ants_quantity = data.quantity_of_ants;
	ways_amount = ft_quantity_of_active_ways(ways);
	j = 0;
	len = (int *)malloc(sizeof(int)*ways_amount);
	ft_init_len(len, ways);
	way = (int *)malloc(sizeof(int)*ways_amount);
	ft_int_way(way, ways_amount);
	while (ants_quantity)
	{
		i = 0;
		if ((way[i] + 1) <= len[j] || ways_amount == 1)
		{
			way[i] += 1;
			ants_quantity--;
		}
		else
		{
			i++;
			while (i < ways_amount)
			{
				if ((way[i] + 1) <= len[j])
				{
					way[i] += 1;
					ants_quantity--;
					break;
				}
				else if (way[i] + 1 > len[j])
				{
					way[ft_find_the_shortest_path(len)] += 1;
					ants_quantity--;
					break;
				}
				i++;
			}
			if (i > j)
				j++;
		}
	}
	ft_update_the_ways_data(ways, way);
	free(len);
	free(way);
}
