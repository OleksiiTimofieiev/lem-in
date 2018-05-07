/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_graph_vertex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 22:03:33 by otimofie          #+#    #+#             */
/*   Updated: 2018/04/30 22:03:34 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_vertex	*ft_vertex_builder(char *line)
{
	t_vertex	*tmp;
	char		**medium_array;

	if (!(tmp = (t_vertex*)malloc(sizeof(t_vertex))))
		return (NULL);
	medium_array = ft_strsplit(line, ' ');
	tmp->vertex_name = ft_strdup(medium_array[0]);
	tmp->e_next = NULL;
	tmp->v_next = NULL;
	tmp->visited = 'w';
	tmp->path = 0;
	ft_clean_2d_char(medium_array);
	return (tmp);
}

static int		ft_valid_type_of_the_line(int type_of_the_line)
{
	if (type_of_the_line == ROOM || type_of_the_line == ROOM_START
		|| type_of_the_line == ROOM_END)
		return (1);
	return (0);
}

void			ft_build_vertex_structure(t_init *initial_data, t_vertex **g)
{
	t_vertex	*current;

	while (initial_data)
	{
		if (ft_valid_type_of_the_line(initial_data->type_of_the_line))
		{
			if (!*g)
				*g = ft_vertex_builder(initial_data->valid_line);
			else
			{
				current = *g;
				while (current->v_next)
					current = current->v_next;
				current->v_next = ft_vertex_builder(initial_data->valid_line);
			}
		}
		initial_data = initial_data->next;
	}
}
