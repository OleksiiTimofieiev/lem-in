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

static t_vertex	*ft_vertex_builder(void)
{
	t_vertex	*tmp;

	if (!(tmp = (t_vertex*)malloc(sizeof(t_vertex))))
		return (NULL);
	tmp->vertex_name = NULL;
	tmp->e_head = NULL;
	tmp->v_head = NULL;
	return (tmp);
}

static int		ft_valid_type_of_the_line(int type_of_the_line)
{
	if (type_of_the_line == ROOM || type_of_the_line == ROOM_START
		|| type_of_the_line == ROOM_END)
		return (1);
	return (0);
}

void	ft_build_vertex_structure(t_init *initial_data, t_vertex *graph)
{
	char		**medium_array;

	medium_array = NULL;
	while (initial_data)
	{
		if (ft_valid_type_of_the_line(initial_data->type_of_the_line))
		{
			medium_array = ft_strsplit(initial_data->valid_line, ' ');

			if (!graph)
			{
				graph = ft_vertex_builder();
				graph->vertex_name = ft_strdup(medium_array[0]);
			}
			else
			{				
				while (graph->v_head)
					graph = graph->v_head;
				graph->v_head = ft_vertex_builder();
				graph->v_head->vertex_name = ft_strdup(medium_array[0]);
			}

			ft_clean_2d_char(medium_array);
		}
		initial_data = initial_data->next;
	}	
}
