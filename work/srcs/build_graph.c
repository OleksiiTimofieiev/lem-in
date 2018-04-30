/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_graph.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 15:09:46 by otimofie          #+#    #+#             */
/*   Updated: 2018/04/30 15:09:47 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_valid_type_of_the_line(int type_of_the_line)
{
	if (type_of_the_line == ROOM || type_of_the_line == ROOM_START
		|| type_of_the_line == ROOM_END)
		return (1);
	return (0);
}

void	ft_build_vertex_structure(t_init *initial_data)
{
	while (initial_data)
	{
		if (ft_valid_type_of_the_line(initial_data->type_of_the_line))
			ft_printf("%s\n", "O.K.");
		initial_data = initial_data->next;
	}
}
