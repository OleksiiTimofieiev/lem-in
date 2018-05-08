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

void	ft_refresh_vertex(t_vertex *vertex) // add some possibilities;
{
	t_edge *tmp;

	while (vertex)
	{
		if (vertex->visited == 'g')
			vertex->visited = 'w';
			
		tmp = vertex->e_next;
		while (tmp)
		{
			if (tmp->visited == 'g')
				tmp->visited = 'w';
			tmp = tmp->next;
		}
		vertex = vertex->v_next;
	}
}

t_edge	*return_corresponding_edge(t_vertex *vertex, t_qnode *node)
{
	while (vertex)
	{
		if (ft_strequ(vertex->vertex_name,node->str))
		{
			// ft_printf("%s\n", vertex->e_next->room_name);
			return (vertex->e_next);
		}
		vertex = vertex->v_next;
	}
	return (NULL);
}

void	ft_print_queue(t_qnode *front)
{
	while (front)
	{
		ft_printf("%s", front->str);
		front = front->next;
	}
	ft_printf("\n");
}

void	bfs(t_data data, t_vertex *vertex) // add some possibilities;
{
	// ft_printf("start-> %s;\n", data.start);
	// ft_printf("end  -> %s;\n", data.end);
	t_queue *queue;
	t_qnode *node;
	t_edge *adj_list_vertex;

	queue = createqueue();

	enqueue(queue, data.start);


	while (!isempty(queue))
	{
		
		node = dequeue(queue);
		ft_printf("Dequeue -> %s\n", node->str);

		
		if (ft_strequ(node->str, data.end))
		{
			ft_printf("%s\n", "Woohoo !");
			return ;
		}


		ft_visited(vertex, node->str, 'b');

		adj_list_vertex = return_corresponding_edge(vertex, node);


		while (adj_list_vertex)
		{
			if (adj_list_vertex->visited != 'g' && adj_list_vertex->visited != 'b')
			{
				enqueue(queue, adj_list_vertex->room_name);
				ft_visited(vertex, adj_list_vertex->room_name, 'g');
			}
			adj_list_vertex = adj_list_vertex->next;
		}
		// ft_print_lg_1(vertex);
		ft_print_queue(queue->front);


	}


	// enqueue(queue, "2");
	// enqueue(queue, "3");
	// enqueue(queue, "4");
	// enqueue(queue, data.end);


	// deleteList(&queue->front);

	// t_qnode *n;
	// free(n->str);
	// free(n);
	
	// n = dequeue(queue);
	// // free(n);

	// n = dequeue(queue);
	// free(n);
	// free(n);
	


	// ft_printf("front-> %s\n", queue->front->str);
	// ft_printf("rear -> %s\n", queue->rear->str);
	// deleteList(&queue->front);

	// ft_refresh_vertex(vertex); /////////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
	// deleteList(&queue->rear);
// 
	free(queue);

}
