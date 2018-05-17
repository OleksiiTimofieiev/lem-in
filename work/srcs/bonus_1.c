/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 19:30:02 by otimofie          #+#    #+#             */
/*   Updated: 2018/05/17 19:30:03 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_detect_bonus_activation(char **argv)
{
	int i;

	i = 0;
	while (argv[i])
	{
		if (ft_strequ(argv[i], "-ways_select"))
			return (1);
		i++;
	}
	return (0);
}

int		ft_detect_sounds(char **argv)
{
	int i;

	i = 0;
	while (argv[i])
	{
		if (ft_strequ(argv[i], "-sounds"))
			return (1);
		i++;
	}
	return (0);
}

int		ft_detect_colors(char **argv)
{
	int i;

	i = 0;
	while (argv[i])
	{
		if (ft_strequ(argv[i], "-colors"))
			return (1);
		i++;
	}
	return (0);
}

void	ft_print_ants_distributed(t_ways *ways)
{
	ft_printf("------------------------------------------------------------\n");
	while (ways)
	{
		ft_printf("way -> %d, ants -> %d.\n", ways->way_id, ways->way_ants);
		ways = ways->next;
	}
	ft_printf("------------------------------------------------------------\n");
}

void	ft_color_set(t_ways *ways)
{
	t_way_option	*opt;
	int				i;

	while (ways)
	{
		i = 1;
		opt = ways->o_next;
		while (opt)
		{
			if (opt->way_vertex != 1)
			{
				opt->color_id = i++;
				if (i > 7)
					i = 1;
			}
			opt = opt->next;
		}
		ways = ways->next;
	}
}
