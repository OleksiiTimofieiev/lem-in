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

static void deleteList(t_qnode** head_ref) /* + */
{
   t_qnode* current = *head_ref;
   t_qnode* next;
 
   while (current != NULL) 
   {
       next = current->next;
       free(current->str);
       free(current);
       current = next;
   }
   *head_ref = NULL;
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

void	bfs(t_data data, t_vertex *vertex) // add some possibilities;
{
	ft_printf("start-> %s;\n", data.start);
	ft_printf("end  -> %s;\n", data.end);

	t_queue *queue;

	queue = createqueue();

	enqueue(queue, data.start);
	enqueue(queue, "2");
	enqueue(queue, "3");
	enqueue(queue, "4");
	enqueue(queue, data.end);


	// deleteList(&queue->front);

	// t_qnode *n;
	// n = dequeue(queue);
	// free(n->str);
	// free(n);
	
	// n = dequeue(queue);
	// // free(n);

	// n = dequeue(queue);
	// free(n);
	// free(n);
	


	ft_printf("front-> %s\n", queue->front->str);
	ft_printf("rear -> %s\n", queue->rear->str);
	deleteList(&queue->front);

	ft_visited(vertex, data.start, 'g');
	ft_refresh_vertex(vertex);
	// deleteList(&queue->rear);
// 
	free(queue);

}
