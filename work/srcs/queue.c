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
 
static t_qnode* newNode(int k)
{
    t_qnode *temp = (t_qnode*)malloc(sizeof(t_qnode));
    temp->key = k;
    temp->next = NULL;
    return temp; 
}

t_queue *createQueue()
{
    t_queue *q = (t_queue*)malloc(sizeof(t_queue));
    q->front = q->rear = NULL;
    return q;
}

void enQueue(t_queue *q, int k)
{

    t_qnode *temp = newNode(k);
    if (q->rear == NULL)
    {
       q->front = q->rear = temp;
       return;
    }
    q->rear->next = temp;
    q->rear = temp;
}
 
t_qnode *deQueue(t_queue *q)
{
    if (q->front == NULL)
       return NULL;
 
    t_qnode *temp = q->front;
    q->front = q->front->next;
 
    if (q->front == NULL)
       q->rear = NULL;
    return temp;
}
