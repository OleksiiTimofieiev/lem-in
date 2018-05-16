/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ways_distribution_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 14:02:44 by otimofie          #+#    #+#             */
/*   Updated: 2018/05/16 14:02:44 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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

void	ft_init_way(int *way, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		way[i] = 0;
		i++;
	}
}

int		q_of_act_w(t_ways *ways)
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

void	ways_1(t_data data, t_ways *ways, int *way, int *len)
{
	int ants_quantity;
	int buf[3];

	buf[0] = 0;
	buf[1] = 0;
	ants_quantity = data.quantity_of_ants;
	buf[2] = q_of_act_w(ways);
	while (ants_quantity)
	{
		buf[0] = 0;
		if ((way[buf[0]] + 1) <= len[buf[1]] || buf[2] == 1)
		{
			way[buf[0]] += 1;
			ants_quantity--;
		}
		else
			way_2(&ants_quantity, way, len, buf);
	}
}
