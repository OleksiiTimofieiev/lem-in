/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 13:04:42 by otimofie          #+#    #+#             */
/*   Updated: 2018/04/25 13:04:43 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_rooms_exist(char **array, t_init *init)
{
	int				room1;
	int				room2;
	char			**medium;
	t_init			*current;

	room1 = 0;
	room2 = 0;
	current = init;
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
	if (room1 == room2)
		return (1);
	return (0);
}

static int		ft_link_aspects(char *str, t_init *init)
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
	else if (!ft_rooms_exist(array, init))
	{
		ft_clean_2d_char(array);
		return (0);
	}
	ft_clean_2d_char(array);
	return (1);
}

int				ft_alpha_and_omega(int *c_det)
{
	if (c_det[1] == 1 && c_det[2] == 1)
		return (1);
	return (0);
}

int				ft_awesome(int *c_det, char *str, t_init *init, int *r_det)
{
	int		checker;
	char	**array;
	int		type_of_the_link;

	checker = 0;
	type_of_the_link = 0;
	if (ft_alpha_and_omega(c_det) && ft_link_aspects(str, init))
	{
		array = ft_strsplit(str, '-');
		if (!ft_strequ(array[0], array[1]))
			type_of_the_link = LINK;
		else if (ft_strequ(array[0], array[1]))
			type_of_the_link = SKIP;
		ft_list_builder(&init, str, type_of_the_link);
		*r_det = 2;
		checker = 1;
		ft_clean_2d_char(array);
	}
	return (checker);
}

int				ft_check_rooms(char *str, int *r_det, int *c_det, t_init **init)
{
	if (c_det[0] == 0 && ft_detect_command(str, c_det))
	{
		ft_list_builder(init, str, VALID_COMMAND);
		return (1);
	}
	else if (c_det[0] == 1 && ft_aspects(str, *init))
	{
		ft_list_builder(init, str, ft_det_line(str, &c_det));
		return (1);
	}
	else if (c_det[0] == 2 && ft_aspects(str, *init))
	{
		ft_list_builder(init, str, ft_det_line(str, &c_det));
		return (1);
	}
	else if (c_det[0] == 0 && ft_aspects(str, *init))
	{
		ft_list_builder(init, str, ft_det_line(str, &c_det));
		return (1);
	}
	else if (c_det[0] == 0 && !(ft_aspects(str, *init)))
		if (ft_awesome(c_det, str, *init, r_det))
			return (1);
	return (0);
}
