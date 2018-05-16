/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ways_distribution_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 14:03:06 by otimofie          #+#    #+#             */
/*   Updated: 2018/05/16 14:03:07 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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

void	way_2(int *ants_quantity, int *way, int *len, int *buf)
{
	buf[0]++;
	while (buf[0] < buf[2])
	{
		if ((way[buf[0]] + 1) <= len[buf[1]])
		{
			way[buf[0]] += 1;
			(*ants_quantity)--;
			break ;
		}
		else if (way[buf[0]] + 1 > len[buf[1]])
		{
			way[ft_find_the_shortest_path(len)] += 1;
			(*ants_quantity)--;
			break ;
		}
		buf[0]++;
	}
	if (buf[0] > buf[1])
		buf[1]++;
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
