/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_graph_edge.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 10:58:32 by otimofie          #+#    #+#             */
/*   Updated: 2018/05/01 10:58:33 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_edge	*ft_edge_builder(char *line)
{
	t_edge	*tmp;

	if (!(tmp = (t_edge*)malloc(sizeof(t_edge))))
		return (NULL);
	tmp->room_name = ft_strdup(line);
	tmp->next = NULL;
	return (tmp);
}

static int		ft_valid_type_of_the_line(int type_of_the_line)
{
	if (type_of_the_line == LINK)
		return (1);
	return (0);
}

void 	add_data_to_the_vertex(t_vertex *vertex, char *medium)
{
	if (!vertex->e_next)
		vertex->e_next = ft_edge_builder(&medium[1]);
	else
	{
		while (vertex->e_next->next)
			vertex->e_next = vertex->e_next->next;
		vertex->e_next->next = ft_edge_builder(&medium[1]);
	}
}

t_vertex	*ft_find_vetex_according_to_a_link(t_vertex *vertex, char *str) // find for the second;
{
	char **medium;

	while (vertex)
	{
		medium = ft_strsplit(vertex->vertex_name, ' ');
		if (ft_strequ(medium[0], str))
		{
			ft_clean_2d_char(medium);
			return (vertex);
		}
		ft_clean_2d_char(medium);
		vertex = vertex->v_next;
	}
	return (NULL);
}

void			ft_build_edge_structure(t_init *initial_data, t_vertex *vertex)
{
	t_vertex	*current;
	char		**medium;

	current = NULL; // maybe delete;
	medium = NULL; // maybe delete;
	while (initial_data)
	{
		if (ft_valid_type_of_the_line(initial_data->type_of_the_line))
		{
			medium = ft_strsplit(initial_data->valid_line, '-');
			current = ft_find_vetex_according_to_a_link(vertex, medium[0]);
			add_data_to_the_vertex(current, *medium);

			ft_clean_2d_char(medium);
		}
		current = NULL; // maybe delete;
		medium = NULL; // maybe delete;
		
		initial_data = initial_data->next;
	}
}

