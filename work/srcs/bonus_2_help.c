/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_2_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 19:59:38 by otimofie          #+#    #+#             */
/*   Updated: 2018/05/17 19:59:40 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		general(t_way_option *general_opt)
{
	int i;

	i = 0;
	while (general_opt)
	{
		i++;
		general_opt = general_opt->next;
	}
	return (i);
}

int		separate(t_way_option *separate_opt)
{
	int i;

	i = 0;
	while (separate_opt)
	{
		if (!separate_opt->way)
			i++;
		separate_opt = separate_opt->next;
	}
	return (i);
}

void	we_have_ended(t_ways *ways)
{
	t_way_option	*general_opt;
	t_way_option	*separate_opt;

	while (ways)
	{
		if (ways->way_ants != 0)
		{
			general_opt = ways->o_next;
			separate_opt = ways->o_next;
			if (general(general_opt) == separate(general_opt))
				ways->way_ants = 0;
		}
		ways = ways->next;
	}
}
