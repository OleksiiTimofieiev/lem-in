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


static void deleteList(t_planb *head_ref)
{
	if (!head_ref)
		return ;
	if (head_ref->next)
		deleteList(head_ref->next);
	free(head_ref->vertex_name);
    free(head_ref->parent);
    free(head_ref);
}

void	ft_visited(t_vertex *vertex, char *str, char c)
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

t_edge	*return_corresponding_edge(t_vertex *vertex, t_qnode *node)
{
	while (vertex)
	{
		if (ft_strequ(vertex->vertex_name, node->str))
			return (vertex->e_next);
		vertex = vertex->v_next;
	}
	return (NULL);
}

void	ft_print_queue(t_qnode *front)
{
	while (front)
	{
		ft_printf("| %s %s | ", front->str, front->parent);
		front = front->next;
	}
	ft_printf("\n");
}

int		ft_check(char *vertex_name, t_way *way)
{
	while (way)
	{
		if (ft_strequ(vertex_name, way->way_room))
			return (0);
		way = way->next;
	}
	return (1);
}

void	ft_refresh_vertex(t_vertex *vertex, t_way *way, t_data data)
{
	t_edge *edge;


	while (vertex)
	{
		if (ft_check(vertex->vertex_name, way) || ft_strequ(vertex->vertex_name, data.start) || ft_strequ(vertex->vertex_name, data.end))
			vertex->visited = 'w';
		edge = vertex->e_next;
		while (edge)
		{
			if (ft_check(edge->room_name, way) || ft_strequ(edge->room_name, data.start) || ft_strequ(edge->room_name, data.end))
				edge->visited = 'w';
			edge = edge->next;
		}
		vertex = vertex->v_next;
	}
}

void	ft_clean_queue_node(t_qnode **node)
{
	free((*node)->str);
	free((*node)->parent);
	free(*node);
}

void ft_start(t_queue **q, t_data data, t_planb	**main_ptr)
{
	*main_ptr = NULL;
	*q = createqueue();
	enqueue(*q, data.start, "root");
	add_to_the_key(main_ptr, data.start, "start");
	
}

void	bfs(t_data data, t_vertex *vertex, t_way **way)
{
	char *first_parent;
	t_queue *queue;
	t_qnode *node;
	t_edge 	*adj_list_vertex;
	t_planb	*main_ptr;

	ft_start(&queue, data, &main_ptr);
	while (!isempty(queue))
	{
		node = dequeue(queue);
		ft_visited(vertex, node->str, 'b');
		if (ft_strequ(node->str, data.end))
		{
			add_to_way(way, node->str);
			t_planb *unno = main_ptr;
			t_planb *unno1;
			while (unno)
			{
				if (ft_strequ(unno->vertex_name, node->str))
					unno1 = unno;
				unno = unno->next;
			}
			first_parent = ft_strdup(unno1->parent);
			while (unno1)
			{
				if (ft_strequ(unno1->vertex_name, first_parent))
				{
					free(first_parent);
					first_parent = ft_strdup(unno1->parent);
					add_to_way(way, unno1->vertex_name);
				}
				unno1 = unno1->prev;
			}
			free(first_parent);
			ft_clean_queue_node(&node);
			while (!isempty(queue))
			{
				node = dequeue(queue);
				ft_clean_queue_node(&node);
			}
			ft_refresh_vertex(vertex, *way, data);
			enqueue(queue, data.start, "root");
			continue ;
		}
		adj_list_vertex = return_corresponding_edge(vertex, node);
		while (adj_list_vertex) 
		{
			if (adj_list_vertex->visited != 'g' && adj_list_vertex->visited != 'b')
			{
				enqueue(queue, adj_list_vertex->room_name, node->str);
				ft_visited(vertex, adj_list_vertex->room_name, 'g');
				add_to_the_key(&main_ptr, adj_list_vertex->room_name, node->str);
			}
			adj_list_vertex = adj_list_vertex->next;
		}
		ft_clean_queue_node(&node);
	}
	(queue) ? free(queue) : 0;
	deleteList(main_ptr);
}
