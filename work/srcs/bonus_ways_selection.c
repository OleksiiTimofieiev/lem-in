/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_ways_selection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 17:39:35 by otimofie          #+#    #+#             */
/*   Updated: 2018/05/14 17:39:36 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	void	ft_print_ways(t_ways *list)
{
	t_way_option *tmp;

	while (list)
	{
		ft_printf("%d -> ", list->way_id);
		tmp = list->o_next;
		while (tmp)
		{
			ft_printf("%s", tmp->node_id);
			if (tmp->next != NULL)
				ft_printf("%c", '-');
			tmp = tmp->next;
		}
		ft_printf(" | way len == %d", list->way_len);
		if (list->activation)
			ft_printf(" | activation == %s;", "true");
		else
			ft_printf(" | activation == %s;", "false");
		ft_printf("\n");
		list = list->next;
	}
}

void			ft_detect_bonus_adm(char **argv)
{
	int i;

	i = 0;
	while (argv[i])
	{
		if (ft_strequ(argv[i], "-l"))
			system("leaks -q lem-in");
		else if (ft_strequ(argv[i], "-clean"))
			system("make fclean");
		i++;
	}
}

void			ft_detect_bonus_ways(char **argv, t_ways *ways)
{
	int i;

	i = 0;
	while (argv[i])
	{
		if (ft_strequ(argv[i], "-ways_select"))
			activate_ways(&ways);
		i++;
	}
}

void			ft_implement_selection(char *line, t_ways **ways)
{
	t_ways	*head;
	int		way_nbr;
	char	*buf;

	buf = line;
	head = *ways;
	while (*buf && *buf != ' ')
	{
		head = *ways;
		way_nbr = ft_atoi(buf);
		while (head)
		{
			if (head->way_id == way_nbr)
				head->activation = 1;
			head = head->next;
		}
		buf++;
	}
}

void			activate_ways(t_ways **ways)
{
	char	*line;
	t_ways	*head;

	head = *ways;
	while (head)
	{
		head->activation = 0;
		head = head->next;
	}
	ft_printf("\nPlease, select the way(-s).\n");
	ft_printf("--------------------------------\n");
	ft_printf("List of ways:\n");
	ft_print_ways(*ways);
	ft_printf("--------------------------------\n");
	ft_printf("Input format: 1,...,2 :)\n");
	ft_printf("--------------------------------\n");
	get_next_line(0, &line);
	ft_printf("--------------------------------\n");
	ft_implement_selection(line, ways);
	free(line);
	ft_print_ways(*ways);
	ft_printf("--------------------------------\n");
}
