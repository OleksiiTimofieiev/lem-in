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

void	bfs(t_data data)
{
	ft_printf("start-> %s;\n", data.start);
	ft_printf("end  -> %s;\n", data.end);

	t_queue *queue;

	queue = createqueue();

	enqueue(queue, 1);
	enqueue(queue, 2);
	enqueue(queue, 3);
	enqueue(queue, 4);
	enqueue(queue, 5);
	enqueue(queue, 6);
	enqueue(queue, 7);


	t_qnode *n = dequeue(queue);
	if (n != NULL)
      ft_printf("Dequeued item is %d;\n", n->key);
  	n = dequeue(queue);
	if (n != NULL)
      ft_printf("Dequeued item is %d;\n", n->key);
  	n = dequeue(queue);
	if (n != NULL)
      ft_printf("Dequeued item is %d;\n", n->key);


}
