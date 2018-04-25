/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 12:19:44 by otimofie          #+#    #+#             */
/*   Updated: 2018/04/25 12:19:45 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_init	*line_builder(char *valid_line, int i)
{
	t_init *tmp;

	if (!(tmp = (t_init*)malloc(sizeof(t_init))))
		return (NULL);
	tmp->type_of_the_line = i;
	tmp->valid_line = ft_strdup(valid_line);
	tmp->prev = NULL;
	tmp->next = NULL;
	return (tmp);
}

void	ft_list_builder(t_init **initial_data, char *valid_line, int i)
{
	t_init **current;

	current = initial_data;
	if (!(*current))
		(*current) = line_builder(valid_line, i);
	else
	{
		while ((*current)->next)
			(*current) = (*current)->next;
		(*current)->next = line_builder(valid_line, i);
		(*current)->next->prev = *current;
	}
}

int		ft_exclusions(t_init *initial_data)
{
	if (initial_data->type_of_the_line == COMMENT)
		return (0);
	else if (initial_data->type_of_the_line == UNVALID_COMMAND)
		return (0);
	else if (initial_data->type_of_the_line == ANTS_QUANTITY)
		return (0);
	else if (initial_data->type_of_the_line == VALID_COMMAND)
		return (0);
	return (1);
}

int		ft_detect_command(char *str, int *c_det)
{
	if (str[0] == '#' && str[1] == '#'
		&& ft_strequ(str, "##start") && c_det[1] == 0)
	{
		c_det[0] = 1;
		c_det[1] = 1;
		return (1);
	}
	else if ((str[0] == '#' && str[1] == '#')
			&& ft_strequ(str, "##end") && c_det[2] == 0)
	{
		c_det[0] = 2;
		c_det[2] = 1;
		return (1);
	}
	return (0);
}

int		ft_det_line(char *str, int **c_det)
{
	if (str[0] == '#' && str[1] != '#')
		return (COMMENT);
	else if ((!ft_strequ(str, "##start") && !ft_strequ(str, "##end"))
			&& (str[0] == '#' && str[1] == '#'))
		return (UNVALID_COMMAND);
	else if (*c_det[0] == 1)
	{
		*c_det[0] = 0;
		return (ROOM_START);
	}
	else if (*c_det[0] == 2)
	{
		*c_det[0] = 0;
		return (ROOM_END);
	}
	else
		return (ROOM);
	return (0);
}
