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

void	ft_error_handler(int read_detector) /* + */
{
	if (read_detector == 0)
		ft_printf("%s\n", "ERROR");
	else if (read_detector == 1)
		ft_printf("%s\n", "ERROR");
	else if (read_detector == 2)
		ft_printf("%s\n", "ERROR");
}

int		ft_rooms_exist(char **array, t_init *initial_data) /* + */
{
	int				room1;
	int				room2;
	char			**medium;
	t_init	*current;

	room1 = 0;
	room2 = 0;
	current = initial_data;
	while (current->prev)
		current = current->prev;
	while (current)
	{
		medium = ft_strsplit(current->valid_line, 32);
		if (ft_strequ(array[0], medium[0]) && current->type_of_the_line != ANTS_QUANTITY)
			room1++;
		if (ft_strequ(array[1], medium[0]) && current->type_of_the_line != ANTS_QUANTITY)
			room2++;
		ft_clean_2d_char(medium);
		current = current->next;
	}
	if (room1 == room2)
		return (1);
	return (0);
}

int		ft_link_validity_aspects(char *str, t_init *initial_data) /* + */
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

int		ft_check_links(char *str, t_init **initial_data) /* + */
{
	if (ft_link_validity_aspects(str, *initial_data))
	{
		ft_list_builder(initial_data, str, LINK);
		return (1);
	}
	return (0);
}

void	ft_validation(t_init **initial_data) /* + */
{
	int		read_detector;
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
		else if (read_detector == 2)
			validity_detector = ft_check_links(line, initial_data);
		if (validity_detector == 0)
		{
			free(line);
			ft_error_handler(read_detector);
			break ;
		}
		free(line);
	}
}


/* Function to delete the entire linked list */
// void deleteList(t_init **initial_data)
// {
//    /* deref head_ref to get the real head */
//    t_init* current = *initial_data;
//    t_init* next;	
 
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

int		main(void) // add build adjacency list method;
{
	t_init *initial_data; //keep the initial valid data;

	initial_data = NULL;

	ft_validation(&initial_data); //validation of the initial data set;

	// if no data -> exit -> test empty file



	// ?display;
	//after build delete and adjecency list;

	t_init *buf2 = initial_data; 
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
