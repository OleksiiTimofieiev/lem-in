/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 13:17:25 by otimofie          #+#    #+#             */
/*   Updated: 2018/05/07 13:17:26 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		deletelist(t_planb *head_ref)
{
	if (!head_ref)
		return ;
	if (head_ref->next)
		deletelist(head_ref->next);
	free(head_ref->vertex_name);
	free(head_ref->parent);
	free(head_ref);
}

int				ft_check(char *vertex_name, t_way *way)
{
	while (way)
	{
		if (ft_strequ(vertex_name, way->way_room))
			return (0);
		way = way->next;
	}
	return (1);
}

void			ft_refresh_vertex(t_vertex *vertex, t_way *way, t_data data)
{
	t_edge *edge;

	while (vertex)
	{
		if (ft_check(vertex->vertex_name, way)
		|| ft_strequ(vertex->vertex_name, data.start)
		|| ft_strequ(vertex->vertex_name, data.end))
			vertex->visited = 'w';
		edge = vertex->e_next;
		while (edge)
		{
			if (ft_check(edge->room_name, way)
			|| ft_strequ(edge->room_name, data.start)
			|| ft_strequ(edge->room_name, data.end))
				edge->visited = 'w';
			edge = edge->next;
		}
		vertex = vertex->v_next;
	}
}

void			ft_start_bfs(t_queue **q, t_data data, t_planb **m, int *wave)
{
	*wave = 0;
	*m = NULL;
	*q = createqueue();
	enqueue(*q, data.start, "root", 0);
	add_to_the_key(m, data.start, "start");
}

void			bfs(t_data data, t_vertex *vertex, t_way **way)
{
	t_queue	*queue;
	t_qnode	*node;
	t_planb	*main_ptr;
	int		wave;

	ft_start_bfs(&queue, data, &main_ptr, &wave);
	while (!isempty(queue))
	{
		node = dequeue(queue);
		ft_visited(vertex, node->str, 'b');
		if (ft_strequ(node->str, data.end))
		{
			b_end(way, &node, &main_ptr, &queue);
			if (node->wave == 1)
				break ;
			ft_refresh_vertex(vertex, *way, data);
			enqueue(queue, data.start, "root", 0);
			continue ;
		}
		node->wave = ++wave;
		add(vertex, node, queue, &main_ptr);
		ft_clean_queue_node(&node);
	}
	(queue) ? free(queue) : 0;
	deletelist(main_ptr);
}
