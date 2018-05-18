/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_stuff_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 14:21:21 by otimofie          #+#    #+#             */
/*   Updated: 2018/05/16 14:21:23 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_error(void)
{
	ft_putstr("ERROR\n");
	exit(0);
}

void	reverse(t_way **head_ref)
{
	t_way *prev;
	t_way *current;
	t_way *next;

	prev = NULL;
	current = *head_ref;
	next = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head_ref = prev;
}

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

void	ft_bonus_usage(void)
{
	ft_printf("------------------------------------------------------------\n");
	ft_printf("Usage:\n");
	ft_printf("        lem-in [flags] [...]\n");
	ft_printf("Flags:\n");
	ft_printf("        -colors\n");
	ft_printf("        -ways_select\n");
	ft_printf("        -sounds\n");
	ft_printf("        -l\n");
	ft_printf("------------------------------------------------------------\n");
}

void	ft_init(t_init **init, t_vertex **vertex, t_data *data, char **argv)
{
	int i;

	i = 0;
	*init = NULL;
	*vertex = NULL;
	data->start = NULL;
	data->end = NULL;
	data->quantity_of_ants = 0;
	while (argv[i])
	{
		if (ft_strequ(argv[i], "-usage"))
		{
			ft_bonus_usage();
			exit(0);
		}
		i++;
	}
}
