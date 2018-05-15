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

void	ft_ways_distribution(t_data data, t_ways *ways)
{
	int ants_quantity;
	int	ways_amount;
	int i;
	int j;


	ants_quantity = data.quantity_of_ants;
	ways_amount = ft_quantity_of_active_ways(ways);
	j = 0;

	// ft_printf("%d\n", ft_quantity_of_active_ways(ways));



	int *len = (int *)malloc(sizeof(int)*ways_amount);
	len[0] = 5;
	len[1] = 4;

	int	way[2] = {0, 0};



	while (ants_quantity)
	{
		i = 0;
		if ((way[i] + 1) <= len[j])
		{
			way[i] += 1;
			ants_quantity--;
			// ft_printf("ants_quantity->%d\n", ants_quantity);

		}
		else
		{
			i++;
			while (i < 2)
			{
				ft_printf("way0->%d\n", way[0]);
				ft_printf("way1->%d\n", way[1]);

				if ((way[i] + 1) <= len[j])
				{
					way[i] += 1;
					ants_quantity--;
					ft_printf("ants_quantity->%d\n", ants_quantity);
					break;
				}
				else if (way[i] + 1 > len[j])
				{
					ft_printf("i->%d\n", i);

					ft_printf("way->%d\n", way[i]);
					ft_printf("len->%d\n", len[j]);
					way[ft_find_the_shortest_path(len)] += 1;
					ants_quantity--;

					ft_putstr("detected\n");
					//find the shortest path and add to it;
				}

				i++;
			}

			if (i > j)
				j++;
		}

	}
		ft_printf("ewwere\n");



	int b = 0;
	while (b < 2)
	{
		ft_printf("%d\n", way[b]);
		b++;
	}
}
