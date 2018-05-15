/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:49:44 by otimofie          #+#    #+#             */
/*   Updated: 2018/05/13 17:20:19 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

static void reverse(t_way** head_ref)
{
    t_way* prev   = NULL;
    t_way* current = *head_ref;
    t_way* next = NULL;
    while (current != NULL)
    {
        next  = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

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

void	ft_print_ways(t_ways *list) // intermidiaty function;
{
	t_way_option *tmp;

	while (list)
	{

		ft_printf("%d -> ", list->way_id);

		tmp = list->o_next;
		while (tmp)
		{
			ft_printf("%s", tmp->node_id);
			if (tmp->next != NULL)
				ft_printf("%c", '-');
			tmp = tmp->next;
		}
		ft_printf(" | way len == %d;", list->way_len);
		ft_printf("\n");
		list = list->next;
	}
}

int		main(int argc, char **argv)
{
	t_init		*initial_data;
	t_vertex	*graph;
	t_way		*way;
	t_ways		*ways;
	t_data		data;

	ft_init_data(&data);
	ft_init(&initial_data, &graph);
	ft_validation(&initial_data);
	ft_to_start(&initial_data);
	ft_detect_input(initial_data);
	ft_print_ll(initial_data);
	ft_build_vertex_structure(initial_data, &graph);
	ft_build_edge_structure(initial_data, graph);
	ft_add_data_to_graph(initial_data, &data);
	bfs(data, graph, &way);
	reverse(&way);
	multiple_ways(way, &ways, data);
	(argc) ? ft_detect_bonus_ways(argv, ways) : 0 ;

	ft_ways_distribution(data, ways);



	(argc) ? ft_detect_bonus_adm(argv) : 0 ;	
	return (0);
}
