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

void	ft_clean_queue_qt(t_qtnode **front) /* + */
{
	t_qtnode* current = *front;
	t_qtnode* next;
 
	while (current) 
   {
	   next = current->next;
	   free(current->name);
	   free(current);
	   current = next;
   }
   *front = NULL;
}

t_tree	*ft_build_node(t_qnode *node, t_tree *tree) /* + */
{
	t_tree *tmp;

	tmp = (t_tree*)malloc(sizeof(t_tree));
	tmp->vertex_name = ft_strdup(node->str);
	tmp->parent = &tree;
	tmp->child = NULL;
	tmp->next = NULL;
	return (tmp);
}

t_qtnode	*newnode(t_tree *element) /* + */
{
	t_qtnode *tmp;

	tmp = (t_qtnode*)malloc(sizeof(t_qtnode));
	tmp->name = ft_strdup((element)->vertex_name);
	tmp->pointer_to_parent = &element;
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

t_qtnode		*dequeue_t(t_qtree *q) /* + */
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
	// free(q->front);
	return (tmp);
}

int				isempty_t(t_qtree *q) /* + */
{
	return (q->rear == NULL);
}

t_tree			**find_tree_element(t_tree **tree, char *str)
{
	t_qtree *queue;
	t_qtnode *node;
	// ft_printf("%s\n", "2.1.");
		ft_printf("in finding-------------------------------%p\n", &*tree);

	queue = createqueue_t();
	// ft_printf("%s\n", "2.2.");

		ft_printf("main tree in search->%p\n", &*tree);
		ft_printf("tree_vertex name->%s\n", (*tree)->vertex_name);
		if((*tree)->child)
		ft_printf("%s\n", (*tree)->child->vertex_name);


	enqueue_t(queue, (*tree));

	while (!isempty_t(queue))
	{
		node = dequeue_t(queue);
		ft_printf("node parent address ->  %p\n", &(node->pointer_to_parent));
		if (ft_strequ(node->name, str))
		{
			ft_putstr("found\n");
			if ((*tree))
				ft_printf("actual parent address->%p\n", (&*tree));

			ft_printf("pointer to parent->%p\n", node->pointer_to_parent);
			t_tree *middle = *node->pointer_to_parent;
			ft_printf("pointer to parent - middle->%p\n", &middle);


			// if (node->next)
				// ft_printf("----------------------%s\n",node->next->name);
			free(node->name);
			// free(node->pointer_to_parent);
			free(node);
			// node = NULL;
			// ft_printf("Pointer in searching    - > %p\n", node->pointer_to_parent); // how ?
			// ft_printf("Pointer in searching    - > %p\n", node); // how ?
			// ft_putstr("\n");
			// ft_printf("%p\n", middle);
			if (queue)
			{
				ft_clean_queue_qt(&queue->front);
				free(queue);
			}
			return (*middle);
		// system("leaks -q lem-in");

		}
		// system("leaks -q lem-in");

		// ft_printf("tree node name 2 ->  %s\n", node->pointer_to_parent->vertex_name);
		// ft_printf("buf->%p\n", node->pointer_to_parent);

		if (node->pointer_to_parent->child == NULL)
			ft_putstr("Hmmm->tree has no children\n");

		t_tree *buf = node->pointer_to_parent->child;
		if(buf)
		ft_printf("123456789 ->>>>>>>>>>%s\n", buf->vertex_name);

		while (buf)
		{
			ft_printf("add child %s\n", buf->vertex_name);
			enqueue_t(queue, buf);
			buf = buf->next;
		}
		free(node->name);
		free(node);
		// free(node->pointer_to_parent);
		// free(buf);
		// 	ft_putstr("WTF\n");
	}
	if (!isempty_t(queue))
	{
		// ft_putstr("--------------------------------------------------------------------------------->not empty");
		ft_clean_queue_qt(&(queue)->front);
	}
	free(queue);

	return (NULL);
}

void	ft_add_children(t_tree *element, t_qnode *node, t_tree *tree) /* + */
{
	t_tree *ele = element;

		ele = element;
	if (!ele->child)
	{
		ele->child = ft_build_node(node, tree);
			ft_printf("------------------------------------------------->element is empty\n");
			ft_printf("%s\n", element->child->vertex_name);
	}

	else
	{
		while (ele->child->next)
		{
			ft_printf("element------------------------------------------------->%s\n", element->vertex_name);
			ele->child = ele->child->next;
		}
		ele->child->next = ft_build_node(node, tree);
	}
}

void	ft_add_to_tree(t_tree **tree, t_qnode *node, t_data data) // add ways;
{
	t_tree *buf = NULL;
// ft_printf("%s\n", "1.1");
	if (!*tree)
	{
		*tree = ft_build_node(node, NULL);
		ft_printf("element added->%s\n", (*tree)->vertex_name);

		
// ft_printf("%s\n", "1.2");
	}
	else
	{
		// t_tree *tmp = *tree;
// ft_printf("%s\n", "1.3");
		// ft_printf("%s\n", "Not empty");
		ft_printf("node name -> %s\n", node->str);
		ft_printf("node parent -> %s\n", node->parent);
		// ft_printf("%s\n", (*tree)->vertex_name);
// ft_printf("%s\n", "1.4");


		// t_tree *buf2 =*tree;
		ft_printf("main tree->%p\n", *tree);

		// system("leaks -q lem-in");
		ft_printf("before finding-------------------------------%p\n", &*tree);
		buf = &*find_tree_element(tree, node->parent); // <-somewhere here;
		ft_printf("after finding-------------------------------%p\n", &buf);

			ft_printf("Pointer after searching - > %p\n", buf);
			if (buf)
			ft_printf("tree++++++++++++++++++++++%s\n", buf->vertex_name);
		// system("leaks -q lem-in");

// ft_printf("%s\n", "1.5");

		if (!*tree)
		{
// ft_printf("%s\n", "1.6");
			// ft_printf("%s\n", "element not found");
		}
		else
		{
// ft_printf("%s\n", "1.7");
			if (buf)
				ft_printf("buf_pointer->%p\n", buf);
			else
				ft_printf("end not found->%p\n", buf);
			if (buf)
				ft_printf("parent ->>>%s\n", buf->vertex_name);
// ft_printf("%s\n", "1.8");
			if (buf)
			{
				ft_add_children(buf, node, buf); // if child it doesn`t exists and root;
				ft_printf("%s\n", buf->vertex_name);
				ft_printf("%s\n", "children have been added");
// ft_printf("%s\n", "1.9");
			}

			// if no buf

			// ft_printf("parent 2->>>%s\n", buf->child->parent->vertex_name);
			// ft_printf("buf_children_name->%s\n", buf->child->vertex_name);

// ft_printf("%s\n", "1.11");
		}
		ft_printf("\n");
	}


if (buf && ft_strequ(node->str, data.end)) // add one node to a current buf; i have pointer to 3 but not 5;
{
	// ft_printf("I did it !\n");
	//add tp way;	
	t_tree *way = buf->child;
// ft_printf("%s\n", "1.14");
	while (way)
	{
		// ft_printf("%s\n", "1.15");
		ft_printf("way node -> %s\n", way->vertex_name);
		// ft_printf("%s\n", "1.16");
		way = *way->parent;
		// ft_printf("%s\n", "1.17");
		// ft_printf("%s\n", "1.18");
	}
		// ft_printf("start ->    %s\n", "0"); //data start;
}
		// ft_printf("%s\n", "--------->segfault2");
		// node = find(tree);
		// node->child = new node of a tree;
	// free(tree->vertex_name);
	// free(*tree);
}
