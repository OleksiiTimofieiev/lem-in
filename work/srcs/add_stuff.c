/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 08:41:01 by otimofie          #+#    #+#             */
/*   Updated: 2018/05/12 08:41:03 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_edge			*return_corresponding_edge(t_vertex *vertex, t_qnode *node)
{
	while (vertex)
	{
		if (ft_strequ(vertex->vertex_name, node->str))
			return (vertex->e_next);
		vertex = vertex->v_next;
	}
	return (NULL);
}

void			ft_visited(t_vertex *vertex, char *str, char c)
{
	t_edge *tmp;

	while (vertex)
	{
		if (ft_strequ(str, vertex->vertex_name))
			vertex->visited = c;
		tmp = vertex->e_next;
		while (tmp)
		{
			if (ft_strequ(str, tmp->room_name))
				tmp->visited = c;
			tmp = tmp->next;
		}
		vertex = vertex->v_next;
	}
}

void			add(t_vertex *v, t_qnode *n, t_queue *q, t_planb **m)
{
	t_edge *adj_list_vertex;

	adj_list_vertex = return_corresponding_edge(v, n);
	while (adj_list_vertex)
	{
		if (adj_list_vertex->visited != 'g' && adj_list_vertex->visited != 'b')
		{
			enqueue(q, adj_list_vertex->room_name, n->str);
			ft_visited(v, adj_list_vertex->room_name, 'g');
			add_to_the_key(m, adj_list_vertex->room_name, n->str);
		}
		adj_list_vertex = adj_list_vertex->next;
	}
}
