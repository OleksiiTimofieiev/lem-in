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

// static void deleteList(t_qnode** head_ref) /* + */
// {
//    t_qnode* current = *head_ref;
//    t_qnode* next;
 
//    while (current != NULL) 
//    {
//        next = current->next;
//        free(current->str);
//        free(current);
//        current = next;
//    }
//    *head_ref = NULL;
// }

void	ft_clean_queue(t_qnode **front)
{
	t_qnode* current = *front;
   t_qnode* next;
 
   while (current) 
   {
       next = current->next;
       free(current->str);
       free(current);
       current = next;
   }
   *front = NULL;
}

void	ft_print_lg_1(t_vertex *vertex) // intermidiaty function;
{
	t_edge *tmp;

	while (vertex)
	{

		ft_printf("%s", vertex->vertex_name);
		ft_printf(" <-%c !->", vertex->visited);

		tmp = vertex->e_next;
		while (tmp)
		{
			ft_printf(" %s", tmp->room_name);
			ft_printf(" <-%c", tmp->visited);

			tmp = tmp->next;
		}
		ft_printf("\n");
		vertex = vertex->v_next;
	}
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

t_edge	*return_corresponding_edge(t_vertex *vertex, t_qnode *node) /* + */
{
	while (vertex)
	{
		if (ft_strequ(vertex->vertex_name, node->str))
			return (vertex->e_next);
		vertex = vertex->v_next;
	}
	return (NULL);
}

void	ft_print_queue(t_qnode *front)
{
	while (front)
	{
		ft_printf("| %s %s | ", front->str, front->parent);
		front = front->next;
	}
	ft_printf("\n");
}

void	bfs(t_data data, t_vertex *vertex) // add some possibilities;
{
	t_queue *queue;
	t_qnode *node;
	t_edge 	*adj_list_vertex;
	t_tree	*tree;

		// ft_printf("%s\n", "1");
	tree = NULL;
	// ft_printf("%s\n", "2");
	queue = createqueue();
	// ft_printf("%s\n", "3");
	enqueue(queue, data.start, "root");
// ft_printf("%s\n", "4");
	while (!isempty(queue))
	{
		// ft_printf("%s\n", "5");
		node = dequeue(queue);
// ft_printf("%s\n", "6");

		// ft_printf("--->dequeue %s\n", node->str);

		// ft_add_to_tree(&tree, node, data);
		
// ft_printf("%s\n", "7");
		
		if (ft_strequ(node->str, data.end))
		{
			// ft_printf("%s\n", "Woohoo !");

			ft_print_queue(queue->front);

			ft_clean_queue(&queue->front);
			ft_clean_queue(&queue->rear);

			// enqueue(queue, data.start);
			enqueue(queue, data.start, "root");

			node = dequeue(queue);
			// free(node->str);
			// free(node->parent);
			// free(node);
			// continue ;
		}

// ft_printf("%s\n", "8");		
		ft_visited(vertex, node->str, 'b'); //except start; // add path only to the nodes which are not end or start;
// ft_printf("%s\n", "9");
		adj_list_vertex = return_corresponding_edge(vertex, node);
// ft_printf("%s\n", "10");
		while (adj_list_vertex) // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<-here
		{
			if (adj_list_vertex->visited != 'g' && adj_list_vertex->visited != 'b')
			{
				enqueue(queue, adj_list_vertex->room_name, node->str);
				ft_visited(vertex, adj_list_vertex->room_name, 'g');
			}
			adj_list_vertex = adj_list_vertex->next;
		}
// ft_printf("%s\n", "11");

		// ft_print_queue(queue->front);
		
		free(node->str);
		free(node->parent);
		free(node);

	}
	// ft_printf("%s\n", tree->vertex_name);
	// ft_printf("first node of a tree - >  %s\n", tree->child->child->vertex_name);
	// ft_printf("first node of a tree - >  %s\n", tree->child->child->vertex_name);

	// free(tree->child->child->vertex_name);
	// free(tree->child->child);

	// free(tree->child->vertex_name);
	// free(tree->child);

	// free(tree->vertex_name);
	free(tree);
	// // ft_printf("first node of a tree - >  %s\n", tree->child->vertex_name);
	// // free(tree->child->vertex_name);
	// free(tree->child);

	// ft_printf("first node of a tree - >  %s\n", tree->vertex_name);
	// free(tree->vertex_name);
			// ft_clean_queue(&queue->front);
	free(queue); // clean all if not empty;
// ft_printf("%s\n", "12");
}
