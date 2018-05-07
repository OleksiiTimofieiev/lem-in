/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 13:38:47 by otimofie          #+#    #+#             */
/*   Updated: 2018/05/07 13:38:49 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	t_qnode	*newnode(char *str)
{
	t_qnode *temp;

	temp = (t_qnode*)malloc(sizeof(t_qnode));
	temp->str = ft_strdup(str);
	temp->next = NULL;
	return (temp);
}

t_queue			*createqueue(void)
{
	t_queue *q;

	q = (t_queue*)malloc(sizeof(t_queue));
	q->front = NULL;
	q->rear = NULL;
	return (q);
}

void			enqueue(t_queue *q, char *str)
{
	t_qnode *temp;

	temp = newnode(str);
	if (q->rear == NULL)
	{
		q->front = temp;
		q->rear = temp;
		return ;
	}
	q->rear->next = temp;
	q->rear = temp;
	// free(temp);
}

t_qnode			*dequeue(t_queue *q)
{
	t_qnode *temp;

	temp = q->front;
	if (q->front == NULL)
		return (NULL);
	if (q->front == q->rear)
	{
		q->front = NULL;
		q->rear = NULL;
	}
	else
		q->front = q->front->next;
	return (temp);
}


