/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 08:34:58 by otimofie          #+#    #+#             */
/*   Updated: 2018/05/12 08:35:02 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_clean_queue_node(t_qnode **node)
{
	free((*node)->str);
	free((*node)->parent);
	free(*node);
}

void			free_remaining_stuff(char *first_parent, t_qnode *n, t_queue *q)
{
	free(first_parent);
	ft_clean_queue_node(&n);
	while (!isempty(q))
	{
		n = dequeue(q);
		ft_clean_queue_node(&n);
	}
}

void			b_end(t_way **w, t_qnode **n, t_planb **m, t_queue **q)
{
	char	*first_parent;
	t_planb *unno;
	t_planb *unno1;

	add_to_way(w, (*n)->str, (*n)->wave);
	unno = *m;
	while (unno)
	{
		if (ft_strequ(unno->vertex_name, (*n)->str))
			unno1 = unno;
		unno = unno->next;
	}
	first_parent = ft_strdup(unno1->parent);
	while (unno1)
	{
		if (ft_strequ(unno1->vertex_name, first_parent))
		{
			free(first_parent);
			first_parent = ft_strdup(unno1->parent);
			add_to_way(w, unno1->vertex_name, (*n)->wave);
		}
		unno1 = unno1->prev;
	}
	free_remaining_stuff(first_parent, *n, *q);
}
