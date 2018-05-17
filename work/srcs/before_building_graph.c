/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_building_graph.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 13:16:20 by otimofie          #+#    #+#             */
/*   Updated: 2018/04/27 13:16:21 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	int		ft_detect_link_start_end(t_init *initial_data)
{
	int		ants;
	int		link;
	int		start;
	int		end;
	t_init	*head;

	ants = 0;
	link = 0;
	start = 0;
	end = 0;
	head = initial_data;
	while (head)
	{
		(head->type_of_the_line == LINK) ? link++ : 0;
		(head->type_of_the_line == ROOM_END) ? end++ : 0;
		(head->type_of_the_line == ROOM_START) ? start++ : 0;
		(head->type_of_the_line == ANTS_QUANTITY) ? ants++ : 0;
		head = head->next;
	}
	if (!ants || !start || !end || !link)
		return (0);
	return (1);
}

int				ft_detect_input(t_init *initial_data)
{
	if (initial_data == NULL)
		return (0);
	else if (!(ft_detect_link_start_end(initial_data)))
		return (0);
	return (1);
}
