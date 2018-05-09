/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 13:17:57 by otimofie          #+#    #+#             */
/*   Updated: 2018/05/09 13:17:59 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_tree	*ft_build_node(t_qnode *node) // for a tree;
{
	t_tree *tmp;

	tmp = (t_tree*)malloc(sizeof(t_tree));
	tmp->vertex_name = ft_strdup(node->str);
	tmp->parent = NULL;
	tmp->child = NULL;
	tmp->next = NULL;
	return (tmp);
}

t_qtnode	*newnode(t_tree *element) // will need to be checked during the dereference;
{
	t_qtnode *tmp;

	tmp = (t_qtnode*)malloc(sizeof(t_qtnode));
	tmp->name = ft_strdup(element->vertex_name);
	tmp->pointer_to_parent = element;
	tmp->next = NULL;
	return (tmp);
}

t_qtree			*createqueue_t(void) /* + */
{
	t_qtree *q;

	q = (t_qtree*)malloc(sizeof(t_qtree));
	q->rear = NULL;
	q->front = q->rear;
	return (q);
}

void			enqueue_t(t_qtree *q, t_tree *element) /* + */
{
	t_qtnode *tmp;

	tmp = newnode(element);
	if (q->rear == NULL && q->front == NULL)
	{
		q->rear = tmp;
		q->front = q->rear;
		return ;
	}
	q->rear->next = tmp;
	q->rear = tmp;
}

t_qtnode			*dequeue_t(t_qtree *q) /* + */
{
	t_qtnode *tmp;

	tmp = q->front;
	if (q->front == NULL)
		return (NULL);
	if (q->front == q->rear)
	{
		q->front = NULL;
		q->rear = NULL;
	}
	else
		q->front = q->front->next;
	return (tmp);
}

int				isempty_t(t_qtree *q) /* + */
{
	return (q->rear == NULL);
}

t_tree	*find_tree_element(t_tree *tree, char *str)
{
	t_qtree *queue;
	t_qtnode *node;

	queue = createqueue_t();
	enqueue_t(queue, tree);
	while (!isempty_t(queue))
	{
		node = dequeue_t(queue);

		if (ft_strequ(node->name, str))
		{
			ft_printf("%p\n", node->pointer_to_parent);
			return (node->pointer_to_parent);
		}

			// ft_putchar('Q');
		while (node->pointer_to_parent->child)
		{
			enqueue_t(queue, node->pointer_to_parent->child);
			node->pointer_to_parent->child = node->pointer_to_parent->child->next;
		}
	}
	return (NULL);
}

void	ft_add_to_tree(t_tree **tree, t_qnode *node)
{
	t_tree *buf;

	if (!*tree)
		*tree = ft_build_node(node);
	else
	{
		ft_printf("%s\n", "Not empty");


		buf = find_tree_element(*tree, node->parent);

		if (!buf)
			ft_printf("%s\n", "element not found"); //add a child to parentl
		else
			ft_printf("Vertex_name ->>>%s\n", buf->vertex_name);
		ft_printf("buf->%p\n", buf);
	}

		// node = find(tree);
		// node->child = new node of a tree;


	// free(tree->vertex_name);
	// free(tree);
}
