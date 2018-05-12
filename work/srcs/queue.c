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

static	t_qnode	*newnode(char *str, char *parent)
{
	t_qnode *tmp;

	tmp = (t_qnode*)malloc(sizeof(t_qnode));
	tmp->str = ft_strdup(str);
	tmp->parent = ft_strdup(parent);
	tmp->next = NULL;
	return (tmp);
}

t_queue			*createqueue(void)
{
	t_queue *q;

	q = (t_queue*)malloc(sizeof(t_queue));
	q->rear = NULL;
	q->front = q->rear;
	return (q);
}

void			enqueue(t_queue *q, char *str, char *parent)
{
	t_qnode *tmp;

	tmp = newnode(str, parent);
	if (q->rear == NULL && q->front == NULL)
	{
		q->rear = tmp;
		q->front = q->rear;
		return ;
	}
	q->rear->next = tmp;
	q->rear = tmp;
}

t_qnode			*dequeue(t_queue *q)
{
	t_qnode *tmp;

	tmp = q->front;
	if (q->front == NULL)
	{
		ft_putstr("here\n");
		return (NULL);
	}
	if (q->front == q->rear)
	{
		q->front = NULL;
		q->rear = NULL;
	}
	else
		q->front = q->front->next;
	return (tmp);
}

int				isempty(t_queue *q)
{
	return (q->rear == NULL);
}
