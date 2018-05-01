/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_graph_edge.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 10:58:32 by otimofie          #+#    #+#             */
/*   Updated: 2018/05/01 10:58:33 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_edge		*ft_edge_builder(char *line)
{
	t_edge	*tmp;

	if (!(tmp = (t_edge*)malloc(sizeof(t_edge))))
		return (NULL);
	tmp->room_name = ft_strdup(line);
	tmp->next = NULL;
	return (tmp);
}

static void			data_to_vertex(t_vertex *vertex, char **medium, int flag)
{
	t_edge *tmp;

	tmp = vertex->e_next;
	// if (flag == 0)
	// 	return ;
	if (!vertex->e_next)
	{
		if (flag == 0)
			vertex->e_next = ft_edge_builder(medium[1]);
		else
			vertex->e_next = ft_edge_builder(medium[0]);
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		if (flag == 0)
			tmp->next = ft_edge_builder(medium[1]);
		else
			tmp->next = ft_edge_builder(medium[0]);
	}
}

static t_vertex		*ft_find_vertex(t_vertex *vertex, char *str)
{
	char **medium;

	while (vertex)
	{
		medium = ft_strsplit(vertex->vertex_name, ' ');
		if (ft_strequ(medium[0], str))
		{
			ft_clean_2d_char(medium);
			return (vertex);
		}
		ft_clean_2d_char(medium);
		vertex = vertex->v_next;
	}
	return (NULL);
}

void				ft_build_edge_structure(t_init *ini, t_vertex *vertex)
{
	int			flag;
	t_vertex	*current;
	char		**medium;

	while (ini)
	{
		if (ini->type_of_the_line == LINK)
		{
			flag = 0;
			medium = ft_strsplit(ini->valid_line, '-');
			current = ft_find_vertex(vertex, medium[0]);
			data_to_vertex(current, medium, flag++);
			current = ft_find_vertex(vertex, medium[1]);
			data_to_vertex(current, medium, flag);
			ft_clean_2d_char(medium);
		}
		ini = ini->next;
	}
}
