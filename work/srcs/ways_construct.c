/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ways_construct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 15:02:21 by otimofie          #+#    #+#             */
/*   Updated: 2018/05/11 15:02:22 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_way	*way_node_constructor(char *str, int wave)
{
	t_way *tmp;

	tmp = (t_way*)malloc(sizeof(t_way));
	tmp->way_room = ft_strdup(str);
	tmp->wave = wave;
	tmp->next = NULL;
	return (tmp);
}

void	add_to_way(t_way **way, char *str, int wave)
{
	t_way *buf;

	if (!*way)
	{
		*way = way_node_constructor(str, wave);
	}
	else
	{
		buf = *way;
		while (buf->next)
			buf = buf->next;
		buf->next = way_node_constructor(str, wave);
	}
}
