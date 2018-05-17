/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 20:02:25 by otimofie          #+#    #+#             */
/*   Updated: 2018/05/17 20:02:26 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	push(t_way_option **head_ref, int new_ant)
{
	t_way_option *new_node;

	new_node = (t_way_option *)malloc(sizeof(t_way_option));
	new_node->ant_number = new_ant;
	new_node->node_id = "tmp";
	new_node->way = *head_ref;
	new_node->way_vertex = 0;
	new_node->color_id = 8;
	new_node->next = *head_ref;
	(*head_ref) = new_node;
}

void	ft_add_ant_nodes_to_the_ways(t_ways *ways)
{
	int				i;
	int				ants_in_a_way;
	t_way_option	**opt;

	i = 1;
	while (ways)
	{
		ants_in_a_way = ways->way_ants;
		opt = &(ways->o_next);
		while (ants_in_a_way)
		{
			push(opt, i++);
			ants_in_a_way--;
		}
		ways = ways->next;
	}
}
