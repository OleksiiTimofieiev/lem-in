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

t_tree	*ft_build_node(t_qnode *node, t_tree *tree) // for a tree;
{
	t_tree *tmp;

	tmp = (t_tree*)malloc(sizeof(t_tree));
	tmp->vertex_name = ft_strdup(node->str);
	tmp->parent = tree;
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
		ft_printf("tree node name ->  %s\n", node->name);

		if (ft_strequ(node->name, str))
		{
			return (node->pointer_to_parent);
		}

		ft_printf("tree node name 2 ->  %s\n", node->pointer_to_parent->vertex_name);
			ft_printf("buf->%p\n", node->pointer_to_parent);


		if (node->pointer_to_parent->child == NULL)
			ft_putstr("Hmmm\n");

		t_tree *buf = node->pointer_to_parent->child;


		while (buf)
		{
			ft_printf("add child %s\n", buf->vertex_name);
			enqueue_t(queue, buf);
			buf = buf->next;
		}
		if (isempty_t(queue))
			ft_putstr("WTF\n");
	}
	return (NULL);
}

void	ft_add_children(t_tree *element, t_qnode *node, t_tree *tree)
{
	t_tree *tmp = element; 


	if (!element->child)
		element->child = ft_build_node(node, tree);
	else
	{
		while (tmp->child->next)
			tmp->child = tmp->child->next;
		tmp->child->next = ft_build_node(node, tree);
	}
}

void	ft_add_to_tree(t_tree **tree, t_qnode *node, t_data data)
{
	t_tree *buf = NULL;
	t_tree *tmp = *tree;

	if (!*tree)
		*tree = ft_build_node(node, NULL);
	else
	{
		ft_printf("%s\n", "Not empty");
		ft_printf("node name -> %s\n", node->str);
		ft_printf("node parent -> %s\n", node->parent);


		ft_printf("%s\n", (*tree)->vertex_name);
		buf = find_tree_element(tmp, node->parent);


		if (!buf)
			ft_printf("%s\n", "element not found");
		else
		{
			ft_printf("buf_pointer->%p\n", buf);
			ft_printf("parent ->>>%s\n", buf->vertex_name);






			ft_add_children(buf, node, buf); // add parent;

			ft_printf("parent 2->>>%s\n", buf->child->parent->vertex_name);


			ft_printf("buf_children_name->%s\n", buf->child->vertex_name);

	
		}
		ft_printf("\n");


	}


	if (ft_strequ(node->str, data.end)) // add one node to a current buf; i have pointer to 3 but not 5;
	{
		ft_printf("I did it !\n");

		//add to a way;
		ft_printf("end ->      %s\n", buf->child->vertex_name);
		
		t_tree *way = buf->child->parent;

		while (!ft_strequ(way->vertex_name, "0"))
		{
			ft_printf("way node -> %s\n", way->vertex_name);
			way = way->parent;
		}
		ft_printf("start ->    %s\n", "0"); //data start;
}

		// node = find(tree);
		// node->child = new node of a tree;


	// free(tree->vertex_name);
	// free(tree);
}
