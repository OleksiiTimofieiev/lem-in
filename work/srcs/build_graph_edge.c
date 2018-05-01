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

static t_edge	*ft_edge_builder(char *line)
{
	t_edge	*tmp;
	char	**medium_array;

	if (!(tmp = (t_edge*)malloc(sizeof(t_edge))))
		return (NULL);
	medium_array = ft_strsplit(line, '-');
	tmp->room_name = ft_strdup(medium_array[1]);
	tmp->next = NULL;
	ft_clean_2d_char(medium_array);
	return (tmp);
}

static int		ft_valid_type_of_the_line(int type_of_the_line)
{
	if (type_of_the_line == LINK)
		return (1);
	return (0);
}

void			ft_build_edge_structure(t_init *initial_data, t_edge **g)
{
	t_edge	*current;

	while (initial_data)
	{
		if (ft_valid_type_of_the_line(initial_data->type_of_the_line))
		{
			if (!*g)
				*g = ft_edge_builder(initial_data->valid_line);
			else
			{
				current = *g;
				while (current->v_next)
					current = current->v_next;
				current->v_next = ft_edge_builder(initial_data->valid_line);
			}
		}
		initial_data = initial_data->next;
	}
}

