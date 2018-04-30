/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:49:44 by otimofie          #+#    #+#             */
/*   Updated: 2018/04/18 12:49:46 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_to_start(t_init **initial_data)
{
	if (*initial_data)
		while ((*initial_data)->prev)
			(*initial_data) = (*initial_data)->prev;
	else
	{
		ft_printf("\n%s\n", "ERROR");
		exit(0);
	}
}

void	ft_print_ll(t_init *data)
{
	while (data)
	{
		ft_printf("%s\n", data->valid_line);
		data = data->next;
	}
}

int		main(void)
{
	t_init		*initial_data;
	t_vertex	*graph;

	initial_data = NULL; // create init function;
	graph = NULL; // create init function;

	ft_validation(&initial_data);
	ft_to_start(&initial_data);
	ft_detect_input(initial_data);
	ft_print_ll(initial_data);

	ft_build_vertex_structure(initial_data);


	system("leaks -q lem-in");
	return (0);
}
