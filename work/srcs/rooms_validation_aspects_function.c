/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms_validation_aspects_function.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:16:30 by otimofie          #+#    #+#             */
/*   Updated: 2018/04/25 16:16:32 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_room_and_coord_unique(char **array, t_init *initial_data)
{
	char	**medium;
	t_init	*current;

	current = initial_data;
	while (current->prev)
		current = current->prev;
	while (current)
	{
		medium = ft_strsplit(current->valid_line, 32);
		if (ft_exclusions(current))
			if (ft_strequ(array[0], medium[0])
			|| ft_strequ(array[1], medium[1]) || ft_strequ(array[2], medium[2]))
			{
				ft_clean_2d_char(medium);
				return (0);
			}
		ft_clean_2d_char(medium);
		current = current->next;
	}
	return (1);
}

int		ft_find_space_is_correct_quantity(char *str)
{
	int i;
	int s_general;
	int s_inline;

	i = 0;
	s_general = 0;
	s_inline = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			s_general++;
		else if (str[i] != ' ' && str[i - 1] == ' ')
			s_inline++;
		i++;
	}
	if ((s_general == s_inline) && s_general == 2)
		return (1);
	return (0);
}

int		ft_aspects_help_1(char *str, int array_size)
{
	if (ft_strequ(str, "##start") || ft_strequ(str, "##end"))
		return (0);
	else if (array_size == 1 && str[0] == '#' && str[1] != '#')
		return (1);
	else if ((!ft_strequ(str, "##start") && !ft_strequ(str, "##end"))
			&& (str[0] == '#' && str[1] == '#'))
		return (1);
	else if (array_size != 3)
		return (0);
	return (1);
}

int		ft_aspects_help_2(char **array)
{
	if (ft_str_find_chr(array[0], '-'))
		return (0);
	else if (ft_2d_arr_size(array) != 1
			&& (array[0][0] == '#' || array[0][0] == 'L'))
		return (0);
	return (1);
}

int		ft_aspects(char *str, t_init *initial_data)
{
	char	**array;
	int		array_size;

	if (!(array = ft_strsplit(str, ' ')))
		return (0);
	array_size = ft_2d_arr_size(array);

	if (!ft_aspects_help_1(str, array_size) || !ft_aspects_help_2(array))
	{
		ft_clean_2d_char(array);
		return (0);
	}
	else if (!ft_find_space_is_correct_quantity(str) && array_size != 1)
	{
		ft_clean_2d_char(array);
		return (0);
	}
	else if (array_size != 1 &&!ft_room_and_coord_unique(array, initial_data) )
	{
		ft_clean_2d_char(array);
		return (0);
	}
	ft_clean_2d_char(array);
	return (1);
}
