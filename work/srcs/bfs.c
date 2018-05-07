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

void deleteList(t_qnode** head_ref)
{
   /* deref head_ref to get the real head */
   t_qnode* current = *head_ref;
   t_qnode* next;
 
   while (current != NULL) 
   {
       next = current->next;
       free(current);
       current = next;
   }
   
   /* deref head_ref to affect the real head back
      in the caller. */
   *head_ref = NULL;
}

void	bfs(t_data data)
{
	ft_printf("start-> %s;\n", data.start);
	ft_printf("end  -> %s;\n", data.end);

	t_queue *queue;

	queue = createqueue();

	enqueue(queue, "1");
	enqueue(queue, "2");
	enqueue(queue, "3");
	enqueue(queue, "4");



	// deleteList(&queue->front);

	// t_qnode *n;
	// n = dequeue(queue);
	// // free(n);
	
	// n = dequeue(queue);
	// // free(n);

	// n = dequeue(queue);
	// free(n);
	// free(n);



	// ft_printf("front->%s\n", queue->front->str);
	// ft_printf("rear ->%s\n", queue->rear->str);

	free(queue);

}
