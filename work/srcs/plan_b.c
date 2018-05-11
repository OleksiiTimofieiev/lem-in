/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 13:28:07 by otimofie          #+#    #+#             */
/*   Updated: 2018/05/11 13:28:09 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_planb	*node_constructor(char *child_str, char *parent_str)
{
	t_planb *tmp;

	tmp = (t_planb*)malloc(sizeof(t_planb));
	tmp->vertex_name = ft_strdup(child_str);
	tmp->parent = ft_strdup(parent_str);
	tmp->prev = NULL;
	tmp->next = NULL;
	return (tmp);
}

void	add_to_the_key(t_planb **ptr, char *child_str, char *parent_str)
{
	t_planb *buf;

	if (!*ptr)
	{
		*ptr = node_constructor(child_str, parent_str);
		(*ptr)->prev = NULL;
	}
	else
	{
		buf = *ptr;
		while (buf->next)
			buf = buf->next;
		buf->next = node_constructor(child_str, parent_str);
		buf->next->prev = buf;
	}
}
