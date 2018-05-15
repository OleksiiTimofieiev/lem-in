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

void	ft_ways_distribution(t_data data, t_ways *ways) // if we have only one way;
{
	int ants_quantity;
	int	ways_amount;
	int i;
	int j;

	// ft_putstr("1\n");
	ants_quantity = data.quantity_of_ants;
	ways_amount = ft_quantity_of_active_ways(ways);
	j = 0;
	// ft_putstr("2\n");


	int *len = (int *)malloc(sizeof(int)*ways_amount);
	ft_init_len(len, ways);
	// ft_putstr("3\n");


	int	*way = (int *)malloc(sizeof(int)*ways_amount);
	ft_int_way(way, ways_amount);
	// way[0] = 0;
	// way[1] = 0;
	// ft_putstr("4\n");



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
	// ft_putstr("5\n");

		}
		// ft_printf("%d\n", ants_quantity);
	}


	// int b = 0;
	// while (b < 2)
	// {
	// 	ft_printf("%d\n", way[b]);
	// 	b++;
	// }
	free(len);
	free(way);
}