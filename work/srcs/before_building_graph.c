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

// no links available, 
// if we do not have start and the end, 
// we have only one link but the start is not connected with the end or we have the 1-1 type of the link;

static	void	ft_error(void)
{
	ft_printf("%s\n", "ERROR");
	exit(0);
}

static	int		ft_valid_link(t_init *initial_data)
{
	// split the link;
	// check that the line has the start and the end;
	return (0);
}

static	int		ft_detect_link_start_end(t_init *initial_data)
{
	int link;
	int start;
	int end;

	link = 0;
	start = 0;
	end = 0;
	while (initial_data)
	{
		if (initial_data->type_of_the_line == 8)
			link++;
		if (initial_data->type_of_the_line == 7)
			end++;
		if (initial_data->type_of_the_line == 6)
			start++;
		initial_data = initial_data->next;
	}
	if (!link || !start || !end || (link == 1 && !ft_valid_link(initial_data)))
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
