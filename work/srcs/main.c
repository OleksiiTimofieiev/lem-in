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
			if (!tmp->way)
				ft_printf("node->a:%d", tmp->ant_number);
			else
				ft_printf("v:%s->a:%d", tmp->way->node_id, tmp->ant_number);
			if (tmp->next != NULL)
				ft_printf("%s", " - ");
			tmp = tmp->next;
		}
		ft_printf(" | way len == %d", list->way_len);
		ft_printf(" | way ants == %d;\n", list->way_ants);
		list = list->next;
	}
}

void push(t_way_option **head_ref, int new_ant)
{
    t_way_option* new_node = (t_way_option*) malloc(sizeof(t_way_option));
  
    new_node->ant_number  = new_ant;
    new_node->node_id  = ft_strdup(ft_itoa(new_ant));

    new_node->way = *head_ref;
    new_node->next = *head_ref;
  
    (*head_ref) = new_node;
}

void	ft_add_ant_nodes_to_the_ways(t_ways *ways)
{
	int i;
	int ants_in_a_way;

	i = 1;
	while (ways)
	{
		ants_in_a_way = ways->way_ants;
		while (ants_in_a_way)
		{
			push(&ways->o_next, i++);
			ants_in_a_way--;
		}
		ft_printf("\n");
		ways = ways->next;
	}
}

void	one_move(t_ways *ways)
 //print result of movement; 
 // how much have null; !!!!!!!!!! null == len; i++ or search;
 //if it points to vertex node;
  // for each way;
  // each way has different length;
//format according to the subject;
{
	t_ways *_ways = ways;
	t_way_option *opt;
	while (_ways)
	{
		if (_ways->way_ants)
		{
			ft_printf("\n");
			opt = _ways->o_next;
			while (opt)
			{
				if (opt->way) // while null !+ quantity of ants;
					opt->way = opt->way->next;
				opt = opt->next;
			}
		}
		_ways = _ways->next;
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
	ft_to_start(&initial_data); // ternary construction;
	ft_detect_input(initial_data); // ternary construction;
	ft_print_ll(initial_data); // ternary construction;
	ft_build_vertex_structure(initial_data, &graph);
	ft_build_edge_structure(initial_data, graph);
	ft_add_data_to_graph(initial_data, &data);
	bfs(data, graph, &way);
	//
	//
	(!way) ? ft_error() : reverse(&way);
	multiple_ways(way, &ways, data);
	(argc) ? ft_detect_bonus_ways(argv, ways) : 0 ;
	d1(data, ways, argc, argv);
	ft_add_ant_nodes_to_the_ways(ways); //leaks ?
	ft_print_ways(ways); //delete;
one_move(ways); //leaks ?
one_move(ways); //leaks ?

one_move(ways); //leaks ?
one_move(ways); //leaks ?
one_move(ways); //leaks ?
one_move(ways); //leaks ?
one_move(ways); //leaks ?
one_move(ways); //leaks ?
one_move(ways); //leaks ?
one_move(ways); //leaks ?
one_move(ways); //leaks ?
one_move(ways); //leaks ?
one_move(ways); //leaks ?



	ft_print_ways(ways); //delete;

	(argc) ? ft_detect_bonus_adm(argv) : 0 ;	
	return (0);
}
