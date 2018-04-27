/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_building_graph.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 13:16:20 by otimofie          #+#    #+#             */
/*   Updated: 2018/04/27 13:16:21 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	void	ft_error(void)
{
	ft_printf("%s\n", "ERROR");
	exit(0);
}

static	int		ft_detect_link_start_end(t_init *initial_data)
{
	int		link;
	int		start;
	int		end;
	t_init	*head;

	link = 0;
	start = 0;
	end = 0;
	head = initial_data;
	while (head)
	{
		if (head->type_of_the_line == LINK)
			link++;
		else if (head->type_of_the_line == ROOM_END)
			end++;
		else if (head->type_of_the_line == ROOM_START)
			start++;
		head = head->next;
	}
	if (!link || !start || !end)
		return (0);
	return (1);
}

void			ft_detect_input(t_init *initial_data)
{
	if (initial_data == NULL)
		ft_error();
	else if (!(ft_detect_link_start_end(initial_data)))
		ft_error();
}
