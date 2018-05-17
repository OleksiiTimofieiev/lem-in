/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 19:52:56 by otimofie          #+#    #+#             */
/*   Updated: 2018/05/17 19:52:57 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	one_move(t_ways *ways)
{
	t_ways			*ways_tmp;
	t_way_option	*opt;

	ways_tmp = ways;
	while (ways_tmp)
	{
		if (ways_tmp->way_ants)
		{
			opt = ways_tmp->o_next;
			while (opt)
			{
				if (opt->way)
					opt->way = opt->way->next;
				opt = opt->next;
			}
		}
		ways_tmp = ways_tmp->next;
	}
}

int		check_ants(t_ways *ways)
{
	while (ways)
	{
		if (ways->way_ants != 0)
			return (1);
		ways = ways->next;
	}
	return (0);
}

void	ft_color_selector(int id)
{
	if (id == 1)
		ft_putstr(GREY);
	else if (id == 2)
		ft_putstr(RED);
	else if (id == 3)
		ft_putstr(GREEN);
	else if (id == 4)
		ft_putstr(YELLOW);
	else if (id == 5)
		ft_putstr(BLUE);
	else if (id == 6)
		ft_putstr(MAGENTA);
	else if (id == 7)
		ft_putstr(CYAN);
	else if (id == 8)
		ft_putstr(WHITE);
}

void	print_moves(t_ways *ways)
{
	t_way_option *opt;

	while (ways)
	{
		opt = ways->o_next;
		while (opt)
		{
			if (opt->way && opt->way->way_vertex == 1)
			{
				ft_color_selector(opt->color_id);
				ft_printf("L%d-%s ", opt->ant_number, opt->way->node_id);
				ft_printf("%s", RESET);
			}
			opt = opt->next;
		}
		ways = ways->next;
	}
}

void	moves(t_ways *ways)
{
	ft_printf("\n");
	while (check_ants(ways))
	{
		one_move(ways);
		print_moves(ways);
		ft_printf("\n");
		we_have_ended(ways);
	}
}
