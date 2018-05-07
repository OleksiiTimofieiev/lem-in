/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_data_to_graph.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 11:45:13 by otimofie          #+#    #+#             */
/*   Updated: 2018/05/07 11:45:15 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_add_data_to_graph(t_init *init, t_data *data)
{
	t_init *tmp;

	tmp = init;
	while (tmp)
	{
		if (tmp->type_of_the_line == ANTS_QUANTITY)
			data->quantity_of_ants = ft_atoi(tmp->valid_line);
		else if (tmp->type_of_the_line == ROOM_START)
			data->start = ft_strnccpy(tmp->valid_line, 32);
		else if (tmp->type_of_the_line == ROOM_END)
			data->end = ft_strnccpy(tmp->valid_line, 32);
		tmp = tmp->next;
	}
}

