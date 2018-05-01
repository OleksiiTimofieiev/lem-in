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

	if (!(tmp = (t_edge*)malloc(sizeof(t_edge))))
		return (NULL);
	tmp->room_name = ft_strdup(line);
	tmp->next = NULL;
	return (tmp);
}

static int		ft_valid_type_of_the_line(int type_of_the_line)
{
	if (type_of_the_line == LINK)
		return (1);
	return (0);
}

// static void		ft_add_data_to_the_edge(t_vertex *vertex, char **medium)
// {
// 	if (ft_strequ(vertex->vertex_name, medium[0]))
// 	{
// 		if (!vertex->e_next)
// 		{
// 			// ft_printf("medium[0] -> %s\n", medium[0]);
// 			// ft_printf("medium[1] -> %s\n", medium[1]);

// 			vertex->e_next = ft_edge_builder(medium[1]);
// 			// ft_printf("vertex_name -> %s\n", vertex->e_next->room_name);

			
// 		}
// 		else
// 		{

// 			// ft_printf("medium[0] -> %s\n", medium[0]);
// 			// ft_printf("medium[1] -> %s\n", medium[1]);
// 			// ft_printf("vertex_name -> %s\n", vertex->e_next->room_name);


			
// 			while (vertex->e_next->next)
// 			{
// 				// ft_printf("%s\n", vertex->e_next->room_name);
// 				vertex->e_next = vertex->e_next->next;
// 			}
// 			vertex->e_next->next = ft_edge_builder(medium[1]);
// 			// ft_printf("%s\n", vertex->e_next);
// 		}
// 	}



// 	else if (ft_strequ(vertex->vertex_name, medium[1]))
// 	{
// 		// if (!vertex->e_next)
// 			// ft_printf("%s\n", "NULL");
// 		// ft_printf("%s\n", "2");
// 	}
// }

// static void	ft_add_edge(t_vertex *vertex, char *valid_line)
// {
// 	char **medium;

// 	medium = ft_strsplit(valid_line, '-');
// 	while (vertex)
// 	{
// 		ft_add_data_to_the_edge(vertex, medium);
// 		vertex = vertex->v_next;
// 	}
// 	ft_clean_2d_char(medium);
// }
void 	add_data_to_the_vertex(t_vertex *vertex, char **medium)
{
	if (!vertex->e_next)
	{
		// ft_printf("vertex->name = %s\n", vertex->vertex_name);
		vertex->e_next = ft_edge_builder(medium[1]);
		// ft_printf("edge->name%s\n", vertex->e_next->room_name);


	}
	else
	{
		// ft_printf("vertex->name = %s\n", vertex->vertex_name);

		while (vertex->e_next->next)
			vertex->e_next = vertex->e_next->next;
		vertex->e_next->next = ft_edge_builder(medium[1]);
		// ft_printf("edge->name%s\n", vertex->e_next->room_name);
	}
}

t_vertex	*ft_find_vetex_according_to_a_link(t_vertex *vertex, char *str) // find for the second;
{
	char **medium;


	while (vertex)
	{
		medium = ft_strsplit(vertex->vertex_name, ' ');
		if (ft_strequ(medium[0], str))
		{
			// ft_printf("O.K.\n");
			ft_clean_2d_char(medium);
			return (vertex);
		}
		ft_clean_2d_char(medium);
		vertex = vertex->v_next;
	}
	return (NULL);
}

void			ft_build_edge_structure(t_init *initial_data, t_vertex *vertex)
{
	t_vertex		*current;
	char **medium;

	while (initial_data)
	{
		if (ft_valid_type_of_the_line(initial_data->type_of_the_line))
		{
			medium = ft_strsplit(initial_data->valid_line, '-');
			current = ft_find_vetex_according_to_a_link(vertex, medium[0]);
			ft_printf("macro->name%s\n", current->vertex_name);
			add_data_to_the_vertex(vertex, medium);
		


			ft_clean_2d_char(medium);
		}
		initial_data = initial_data->next;
	}
}

	// if (!*g)
	// 	*g = ft_edge_builder(initial_data->valid_line);
	// else
	// {
	// 	current = *g;
	// 	while (current->v_next)
	// 		current = current->v_next;
	// 	current->v_next = ft_edge_builder(initial_data->valid_line);
	// }
