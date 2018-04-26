/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 13:51:09 by otimofie          #+#    #+#             */
/*   Updated: 2018/04/25 13:51:10 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_rooms_exist(char **array, t_init *initial_data)
{
	int		room1;
	int		room2;
	char	**medium;
	t_init	*current;

	room1 = 0;
	room2 = 0;
	current = initial_data;
	while (current->prev)
		current = current->prev;
	while (current)
	{
		medium = ft_strsplit(current->valid_line, 32);
		if (ft_strequ(array[0], medium[0])
			&& current->type_of_the_line != ANTS_QUANTITY)
			room1++;
		if (ft_strequ(array[1], medium[0])
			&& current->type_of_the_line != ANTS_QUANTITY)
			room2++;
		ft_clean_2d_char(medium);
		current = current->next;
	}
	if (room1 == room2 && room1 != 0 && room2 != 0)
		return (1);
	return (0);
}

static int		ft_link_validity_aspects(char *str, t_init *initial_data)
{
	char	**array;
	int		array_size;

	if (str[0] == '#' && str[1] != '#')
		return (1);
	else if (!ft_check_quantity(str, '-', 1))
		return (0);
	array = ft_strsplit(str, '-');
	array_size = ft_2d_arr_size(array);
	if (array_size != 2)
	{
		ft_clean_2d_char(array);
		return (0);
	}
	else if (!ft_rooms_exist(array, initial_data))
	{
		ft_clean_2d_char(array);
		return (0);
	}
	ft_clean_2d_char(array);
	return (1);
}

static	int		ft_detect_link_command(char *str)
{
	char **array;

	array = ft_strsplit(str, '-');
	if (!ft_strequ(array[0], array[1]))
	{
		ft_clean_2d_char(array);
		return (LINK);
	}
	else if (ft_strequ(array[0], array[1]))
	{
		ft_clean_2d_char(array);
		return (SKIP);
	}
	return (0);
}

int				ft_check_links(char *str, t_init **initial_data)
{
	if (ft_link_validity_aspects(str, *initial_data))
	{
		ft_list_builder(initial_data, str, ft_detect_link_command(str));
		return (1);
	}
	return (0);
}
