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

static void deleteList(t_qnode** head_ref)
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

void	bfs(t_data data)
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
	


		ft_printf("front->%s\n", queue->front->str);
		ft_printf("rear ->%s\n", queue->rear->str);
		deleteList(&queue->front);
		// deleteList(&queue->rear);
// 
	free(queue);

}
