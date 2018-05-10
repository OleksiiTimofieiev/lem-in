/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:49:44 by otimofie          #+#    #+#             */
/*   Updated: 2018/04/18 12:49:46 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_to_start(t_init **initial_data) // el kostello ultima;
{
	if (*initial_data)
		while ((*initial_data)->prev)
			(*initial_data) = (*initial_data)->prev;
	else
	{
		ft_printf("\n%s\n", "ERROR");
		exit(0);
	}
}

void	ft_print_ll(t_init *data)
{
	while (data)
	{
		ft_printf("%s\n", data->valid_line);
		data = data->next;
	}
}

void	ft_init_data(t_data *data)
{
	data->start = NULL;
	data->end = NULL;
	data->quantity_of_ants = 0;
}

void	ft_init(t_init **init, t_vertex **vertex)
{
	*init = NULL;
	*vertex = NULL;
	// *data = NULL;
}

void	ft_print_lg(t_vertex *vertex) // intermidiaty function;
{
	t_edge *tmp;

	while (vertex)
	{

		ft_printf("%s", vertex->vertex_name);
		ft_printf(" <-%c !->", vertex->visited);

		tmp = vertex->e_next;
		while (tmp)
		{
			ft_printf(" %s", tmp->room_name);
			ft_printf(" <-%c", tmp->visited);

			tmp = tmp->next;
		}
		ft_printf("\n");
		vertex = vertex->v_next;
	}
}

int		main(void)
{
	t_init		*initial_data;
	t_vertex	*graph;
	t_data		data;
	// ways;

	ft_init_data(&data);
	ft_init(&initial_data, &graph);
	ft_validation(&initial_data);
	ft_to_start(&initial_data);
	ft_detect_input(initial_data);
	ft_print_ll(initial_data);
	ft_build_vertex_structure(initial_data, &graph);
	ft_build_edge_structure(initial_data, graph);
	ft_add_data_to_graph(initial_data, &data);

	ft_print_lg(graph);  // intermidiaty function;


	bfs(data, graph);
	ft_putstr("here\n");

	ft_printf("\n");
	// ft_print_lg(graph);  // intermidiaty function;
	
	system("leaks -q lem-in");

	return (0);
}
