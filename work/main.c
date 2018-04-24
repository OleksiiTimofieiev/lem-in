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

t_str_keeper	*line_builder(char *valid_line, int i) /* + */
{
	t_str_keeper *tmp;

	if (!(tmp = (t_str_keeper*)malloc(sizeof(t_str_keeper))))
		return (NULL);
	tmp->type_of_the_line = i;
	tmp->valid_line = ft_strdup(valid_line);
	tmp->prev = NULL;
	tmp->next = NULL;
	return (tmp);
}

void	ft_list_builder(t_str_keeper **initial_data, char *valid_line, int i) /* + */
{
	t_str_keeper **current;

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
	// ft_putchar('4');
}

void	ft_error_handler(int read_detector) /* + */
{
	if (read_detector == 0)
		ft_printf("%s\n", "ERROR");
	else if (read_detector == 1)
		ft_printf("%s\n", "ERROR");
	else if (read_detector == 2)
		ft_printf("%s\n", "ERROR");
}

int		ft_ant_check(char *str, int *read_detector, t_str_keeper **initial_data) /* + */
{
	int		i;

	i = 0;
	if (str[0] == '#' && str[1] == '#' && (!ft_strequ(str, "##start") && !ft_strequ(str, "##end")))
	{
		ft_list_builder(initial_data, str, UNVALID_COMMAND);
		return (1);
	}
	else if (str[0] == '#' && str[1] != '#')
	{
		ft_list_builder(initial_data, str, COMMENT);
		return (1);
	}
	else
	{
		if (!ft_strlen(str) || ft_strlen(str) < 1 || ft_strlen(str) > 10)
			return (0);
		while (i < (int)ft_strlen(str))
			if (ft_isdigit(str[i]) && ft_atoi(&str[0]) != 0)
				i++;
			else
				return (0);
		ft_list_builder(initial_data, str, ANTS_QUANTITY);
		*read_detector = 1;
		return (1);
	}
}

int		ft_detect_command(char *str, int *command_detector) /* + */
{
	if (str[0] == '#' && str[1] == '#' && ft_strequ(str, "##start") && command_detector[1] == 0)
	{
		command_detector[0] = 1;
		command_detector[1] = 1;
		return (1);
	}
	else if ((str[0] == '#' && str[1] == '#') && ft_strequ(str, "##end") && command_detector[2] == 0)
	{
		command_detector[0] = 2;
		command_detector[2] = 1;
		return (1);
	}
	return (0);
}

int		ft_find_space_is_correct_quantity(char *str) /* + */
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

int		ft_exclusions(t_str_keeper *initial_data) /* + */
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

int		ft_room_and_coord_unique(char **array, t_str_keeper *initial_data) /* + */
{
	char			**medium;
	t_str_keeper	*current;

	current = initial_data;
	while (current->prev)
		current = current->prev;
	while (current)
	{
		medium = ft_strsplit(current->valid_line, 32);
		if (ft_exclusions(current))
			if (ft_strequ(array[0], medium[0]) || ft_strequ(array[1], medium[1]) || ft_strequ(array[2], medium[2]))
			{
				ft_clean_2d_char(medium);
				return (0);
			}
		ft_clean_2d_char(medium);
		current = current->next;
	}
	return (1);
}

int		ft_room_validity_aspects(char *str, t_str_keeper *initial_data) /* + */
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
	else if (!ft_isposint(array[1]) || !ft_isposint(array[2]) || !ft_find_space_is_correct_quantity(str))
	{
		ft_clean_2d_char(array);
		return (0); //free too
	}
	else if (!ft_room_and_coord_unique(array, initial_data))
	{
		ft_clean_2d_char(array);
		return (0);
	}
	ft_clean_2d_char(array);
	return (1);
}

int		ft_alpha_and_omega(int *command_detector) /* + */
{
	if (command_detector[1] && command_detector[2])
		return (1);
	return (0);
}

int		ft_detect_type_of_the_line(char *str, int **command_detector) /* + */
{
	if (str[0] == '#' && str[1] != '#')
		return (COMMENT);
	else if ((!ft_strequ(str, "##start") && !ft_strequ(str, "##end")) && (str[0] == '#' && str[1] == '#'))
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

int		ft_check_rooms(char *str, int *read_detector, int *command_detector, t_str_keeper **initial_data) // finalize with invalid room, but a valid link;
{
	if (command_detector[0] == 0 && ft_detect_command(str, command_detector))
	{
		ft_list_builder(initial_data, str, VALID_COMMAND);
		return (1);
	}
	else if (command_detector[0] == 1 && ft_room_validity_aspects(str, *initial_data))
	{
		ft_list_builder(initial_data, str, ft_detect_type_of_the_line(str, &command_detector));
		return (1);
	}
	else if (command_detector[0] == 2 && ft_room_validity_aspects(str, *initial_data))
	{
		ft_list_builder(initial_data, str, ft_detect_type_of_the_line(str, &command_detector));
		return (1);
	}
	else if (command_detector[0] == 0 && ft_room_validity_aspects(str, *initial_data))
	{
		ft_list_builder(initial_data, str, ft_detect_type_of_the_line(str, &command_detector));
		return (1);
	}
	else if (command_detector[0] == 0 && !(ft_room_validity_aspects(str, *initial_data))) // think it over
	{
		// 1. check if we have start and end;
		// 2. check if the link is valid
		if (ft_alpha_and_omega(command_detector)) // and a valid link and not a room, else ->
			ft_printf("%s\n", "Maybe we have a link ?");
		*read_detector = 2;
		// add data to list;
		return (0); // we can use exit (0) <- no links -> nothing to build
	}
	return (0);
}

int		ft_check_quantity(char *str)
{
	int i;
	int count;

	i = 0;
	while(str[i])
	{
		if (str[i] == '-')
			count++;
		i++;
	}
	if (count == 1)
		return (1);
	return (0);
}

int 	ft_link_validity_aspects(char *str, t_str_keeper *initial_data)
{
	char	**array;
	int		array_size;

	if (str[0] == '#' && str[1] != '#')
		return (1);
	else if ()





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

	ft_clean_2d_char(array);
	
	if (!(array = ft_strsplit(str, ' ')))
		return (0);
	array_size = ft_2d_arr_size(array);

		else if (!ft_room_and_coord_unique(array, initial_data))
	{
		ft_clean_2d_char(array);
		return (0);
	}
	
	return (1);

}

int		ft_check_link(char *str, int *read_detector, int *command_detector, t_str_keeper **initial_data)
{
	if (link is valid)
		add to list;
}

void	ft_validation(t_str_keeper **initial_data) // finalyze with links;
{
	int 	read_detector;
	int		validity_detector;
	int		command_detector[3]; 
	char	*line;

	read_detector = 0;
	command_detector[0] = 0;
	command_detector[1] = 0;
	command_detector[2] = 0;
	while (get_next_line(0, &line) == 1)
	{
		if (read_detector == 0)
			validity_detector = ft_ant_check(line, &read_detector, initial_data);
		else if (read_detector == 1)
			validity_detector = ft_check_rooms(line, &read_detector, command_detector, initial_data);
		// else if (initial_data_set->read_detector == 2)
		// 	...
		if (validity_detector == 0)
		{
			free(line);
			ft_error_handler(read_detector);
			break ;
		}
		free(line);
	}
	ft_printf("read_detector -> %d\n", read_detector);
}

/* Function to delete the entire linked list */
// void deleteList(t_str_keeper **initial_data)
// {
//    /* deref head_ref to get the real head */
//    t_str_keeper* current = *initial_data;
//    t_str_keeper* next;	
 
//    while (current != NULL) 
//    {
//        next = current->next;
//        free(current->valid_line);
//        free(current);
//        current = next;
//    }
   
//    /* deref head_ref to affect the real head back
//       in the caller. */
//    *initial_data = NULL;
// }

int		main(void)
{
	t_str_keeper *initial_data; //keep the initial valid data;

	initial_data = NULL;

	ft_validation(&initial_data); //validation of the initial data set;



	t_str_keeper *buf2 = initial_data; 
	while (buf2->prev)
		buf2 = (buf2)->prev;
	while (buf2)
	{
		ft_printf("%s\n", buf2->valid_line);
		buf2 = buf2->next;
	}
	system ("leaks lem-in");
	return (0);
}
