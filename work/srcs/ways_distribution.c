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

void	ft_ways_2(int *ants_quantity, int *way, int *len, int *buf)
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

void	ft_ways_1(t_data data, t_ways *ways, int *way, int *len)
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
			ft_ways_2(&ants_quantity, way, len, buf);
	}
}

void	ft_ways_distribution(t_data data, t_ways *ways, int argc, char **argv)
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
	ft_int_way(way, ways_amount);
	ft_ways_1(data, ways, way, len);
	ft_update_the_ways_data(ways, way);
	free(len);
	free(way);
}
