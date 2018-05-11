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

// static void deleteList(t_qnode** head_ref) /* + */
// {
//    t_qnode* current = *head_ref;
//    t_qnode* next;
 
//    while (current != NULL) 
//    {
//        next = current->next;
//        free(current->str);
//        free(current);
//        current = next;
//    }
//    *head_ref = NULL;
// }

void	ft_clean_queue(t_qnode **front)
{
	t_qnode* current = *front;
   t_qnode* next;
 
   while (current) 
   {
       next = current->next;
       free(current->str);
       free(current);
       current = next;
   }
   *front = NULL;
}

void	ft_print_lg_1(t_vertex *vertex) // intermidiaty function;
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

void	ft_visited(t_vertex *vertex, char *str, char c) /* + */
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

t_edge	*return_corresponding_edge(t_vertex *vertex, t_qnode *node) /* + */
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
		{
			// ft_printf("room: %s" , vertex->vertex_name);
			vertex->visited = 'w';
		}
		edge = vertex->e_next;
		while (edge)
		{
			if (ft_check(edge->room_name, way) || ft_strequ(edge->room_name, data.start) || ft_strequ(edge->room_name, data.end))
			{
				// ft_printf("subroom->%s" , edge->room_name);
				edge->visited = 'w';
			}
			edge = edge->next;
		}
		ft_printf("\n");
		vertex = vertex->v_next;
	}
}

void	bfs(t_data data, t_vertex *vertex, t_way **way) // add some possibilities;
{
	t_queue *queue;
	t_qnode *node;
	t_edge 	*adj_list_vertex;
	t_planb	*main_ptr;

	main_ptr = NULL;
	add_to_the_key(&main_ptr, "1", "w");
	// ft_printf("%s\n", "1");
	// ft_printf("%s\n", "2");
	queue = createqueue();
	// ft_printf("%s\n", "3");
	enqueue(queue, data.start, "root");
	// ft_printf("%s\n", "4");
	while (!isempty(queue))
	{
		node = dequeue(queue);

		if (ft_strequ(node->str, data.end))
		{
			// ft_printf("way from->%s\n", node->str);

			add_to_way(way, node->str);




			// if (queue->front)
			// {
			// 	free(queue->front);
			// 	// queue->front = NULL;
			// }
			ft_printf("%s\n", "Woohoo !");

			t_planb *unno = main_ptr;
			t_planb *unno1;

			while (unno)
			{
				// ft_printf("forvard->%s parent->%s\n", unno->vertex_name, unno->parent);
				if (ft_strequ(unno->vertex_name, node->str))
					unno1 = unno;
				unno = unno->next;
			}

			ft_printf("\n");

			char *first_parent = ft_strdup(unno1->parent);
			// ft_printf("first_parent->%s\n", first_parent);
			// ft_printf("first_current->%s\n", unno1->vertex_name);

			while (unno1)
			{
				if (ft_strequ(unno1->vertex_name, first_parent))
				{
					first_parent = ft_strdup(unno1->parent);
					add_to_way(way, unno1->vertex_name);

					// ft_printf("%s\n", "parent has been found");
					// ft_printf("current->%s\n", unno1->vertex_name);

				}
				// ft_printf("reverse->%s parent->%s\n", unno1->vertex_name, unno1->parent);
				unno1 = unno1->prev;
			}
			// ft_printf("%s\n", "continue");
			ft_printf("\n");
			// ft_refresh_vertex(*way);

			// ft_print_lg_1(vertex);

			while (!isempty(queue))
			{
				node = dequeue(queue);
			}

			ft_refresh_vertex(vertex, *way, data);

			ft_print_lg_1(vertex);
			
			enqueue(queue, data.start, "root");
			ft_printf("\n");
			
			

			ft_printf("\n");
			free(node->str);
			free(node->parent);
			free(node);


			continue ;
		}
		// ft_printf("%s\n", "8");		
		ft_visited(vertex, node->str, 'b');
			// ft_printf("%s\n", "9");
		adj_list_vertex = return_corresponding_edge(vertex, node);
		// ft_printf("%s\n", "10");
		ft_printf("parent ->%s\n", node->str);

		while (adj_list_vertex) 
		{
			if (adj_list_vertex->visited != 'g' && adj_list_vertex->visited != 'b')
			{
				enqueue(queue, adj_list_vertex->room_name, node->str);
				ft_visited(vertex, adj_list_vertex->room_name, 'g');
				ft_printf("to add ->%s\n", adj_list_vertex->room_name);
				add_to_the_key(&main_ptr, adj_list_vertex->room_name, node->str);
			}
			adj_list_vertex = adj_list_vertex->next;
		}
		ft_printf("\n");

		free(node->str);
		free(node->parent);
		free(node);
	}
	// ft_printf("first node of a tree - >  %s\n", tree->vertex_name);
	// free(tree->vertex_name);
			// ft_clean_queue(&queue->front);
	if (queue)
		free(queue); // clean all if not empty;
	// ft_printf("%s\n", "12");



}
