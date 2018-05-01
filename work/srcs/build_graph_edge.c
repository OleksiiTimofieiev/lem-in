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

// static t_edge	*ft_edge_builder(char *line)
// {
// 	t_edge	*tmp;

// 	if (!(tmp = (t_edge*)malloc(sizeof(t_edge))))
// 		return (NULL);
// 	tmp->room_name = ft_strdup(line);
// 	tmp->next = NULL;
// 	return (tmp);
// }

static int		ft_valid_type_of_the_line(int type_of_the_line)
{
	if (type_of_the_line == LINK)
		return (1);
	return (0);
}

static void		ft_add_data_to_the_edge(t_vertex *vertex, char **medium)
{
	if (ft_strequ(vertex->vertex_name, medium))
}

static void	ft_add_edge(t_vertex *vertex, char *valid_line)
{
	char **medium;

	medium = ft_strsplit(valid_line, '-');

	while (vertex)
	{
		ft_printf("%s\n", vertex->vertex_name);
		
		ft_printf("m0->%s\n", medium[0]);
		ft_printf("m1->%s\n", medium[1]);

		vertex = vertex->v_next;
	}
	ft_clean_2d_char(medium);
}

void			ft_build_edge_structure(t_init *initial_data, t_vertex *g)
{
	// t_edge	*current; // ?

	while (initial_data)
	{
		if (ft_valid_type_of_the_line(initial_data->type_of_the_line)) // +
		{
			ft_add_edge(g, initial_data->valid_line);
		}
		initial_data = initial_data->next;
	}
}

	// if (!*g)
	// 	*g = ft_edge_builder(initial_data->valid_line);
	// else
	// {
	// 	current = *g;
	// 	while (current->v_next)
	// 		current = current->v_next;
	// 	current->v_next = ft_edge_builder(initial_data->valid_line);
	// }
