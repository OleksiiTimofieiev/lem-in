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

int		ft_detect_command(char *str, int *command_detector)
{
	if (str[0] == '#' && str[1] == '#'
		&& ft_strequ(str, "##start") && command_detector[1] == 0)
	{
		command_detector[0] = 1;
		command_detector[1] = 1;
		return (1);
	}
	else if ((str[0] == '#' && str[1] == '#')
			&& ft_strequ(str, "##end") && command_detector[2] == 0)
	{
		command_detector[0] = 2;
		command_detector[2] = 1;
		return (1);
	}
	return (0);
}

int		ft_check_quantity(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '-')
			count++;
		i++;
	}
	if (count == 1)
		return (1);
	return (0);
}

static int		ft_rooms_exist(char **array, t_init *initial_data)
{
	int				room1;
	int				room2;
	char			**medium;
	t_init			*current;

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
	if (room1 == room2)
		return (1);
	return (0);
}

int		ft_detect_type_of_the_line(char *str, int **command_detector)
{
	if (str[0] == '#' && str[1] != '#')
		return (COMMENT);
	else if ((!ft_strequ(str, "##start") && !ft_strequ(str, "##end"))
			&& (str[0] == '#' && str[1] == '#'))
		return (UNVALID_COMMAND);
	else if (*command_detector[0] == 1)
	{
		*command_detector[0] = 0;
		return (ROOM_START);
	}
	else if (*command_detector[0] == 2)
	{
		*command_detector[0] = 0;
		return (ROOM_END);
	}
	else
		return (ROOM);
	return (0);
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

int		ft_aspects(char *str, t_init *initial_data)
{
	char	**array;
	int		array_size;

	if (!(array = ft_strsplit(str, ' ')))
		return (0);
	array_size = ft_2d_arr_size(array);
	if (ft_strequ(str, "##start") || ft_strequ(str, "##end"))
	{
		ft_clean_2d_char(array);
		return (0);
	}
	else if (array_size == 1 && str[0] == '#' && str[1] != '#')
	{
		ft_clean_2d_char(array);
		return (2);
	}
	else if ((!ft_strequ(str, "##start") && !ft_strequ(str, "##end"))
			&& (str[0] == '#' && str[1] == '#'))
	{
		ft_clean_2d_char(array);
		return (2);
	}
	else if (array_size != 3)
	{
		ft_clean_2d_char(array);
		return (0);
	}
	else if (ft_str_find_chr(array[0], '-'))
	{
		ft_clean_2d_char(array);
		return (0);
	}
	else if (array[0][0] == '#' || array[0][0] == 'L')
	{
		ft_clean_2d_char(array);
		return (0);
	}
	else if (!ft_find_space_is_correct_quantity(str))
	{
		ft_clean_2d_char(array);
		return (0);
	}
	else if (!ft_room_and_coord_unique(array, initial_data))
	{
		ft_clean_2d_char(array);
		return (0);
	}
	ft_clean_2d_char(array);
	return (1);
}

int		ft_alpha_and_omega(int *command_detector)
{
	if (command_detector[1] == 1 && command_detector[2] == 1)
		return (1);
	return (0);
}

static int		ft_link_validity_aspects(char *str, t_init *initial_data)
{
	char	**array;
	int		array_size;

	if (str[0] == '#' && str[1] != '#')
		return (1);
	else if (!ft_check_quantity(str))
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

int		ft_check_rooms(char *str, int *read_detector, int *command_detector, t_init **initial_data)
{
	if (command_detector[0] == 0 && ft_detect_command(str, command_detector))
	{
		ft_list_builder(initial_data, str, VALID_COMMAND);
		return (1);
	}
	else if (command_detector[0] == 1 && ft_aspects(str, *initial_data))
	{
		ft_list_builder(initial_data, str, ft_detect_type_of_the_line(str, &command_detector));
		return (1);
	}
	else if (command_detector[0] == 2 && ft_aspects(str, *initial_data))
	{
		ft_list_builder(initial_data, str, ft_detect_type_of_the_line(str, &command_detector));
		return (1);
	}
	else if (command_detector[0] == 0 && ft_aspects(str, *initial_data))
	{
		ft_list_builder(initial_data, str, ft_detect_type_of_the_line(str, &command_detector));
		return (1);
	}
	else if (command_detector[0] == 0 && !(ft_aspects(str, *initial_data)))
	{
		if (ft_alpha_and_omega(command_detector) && ft_link_validity_aspects(str, *initial_data))
		{
			ft_list_builder(initial_data, str, LINK);
			*read_detector = 2;
			return (1);
		}
	}
	return (0);
}
