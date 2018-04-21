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

// if the line is valid -> save this shitty something;
// then function to output this shitty stuff;
// how to stop reading; <-break and continue; print smth and continue;
// remaster data structure to the new idea
// get the intermidiary keeper -> have the graph built (node`s categoty will be a criteria);
// stderror -> type of the mistake;
// (get_next_line(0, &line) > 0 && (!has_char(&line, '-')))
//  (ret && get_next_line(0, &line) > 0 && ft_strcmp(line, "") != 0)
//	strsplit for the line;
//	function to detect the rooms or links; if split returns false in a way;

#include "lem_in.h"

void	ft_error_handler(int read_detector)
{
	if (read_detector == 0)
		ft_printf("%s\n", "ERROR: NO ANTS DATA ...");
	else if (read_detector == 1)
		ft_printf("%s\n", "ERROR: INVALID ROOM ...");
	else if (read_detector == 2)
		ft_printf("%s\n", "ERROR: INVALID LINK ...");
}

int		ft_ant_check(char *str, int *read_detector) // add linked list methods;
{
	int		i;

	i = 0;
	if (str[0] == '#' && str[1] == '#')
		return (0);
	else if (str[0] == '#')
	{
		// ft_build(... , correspondent define);
		ft_printf("%s\n", "create a linked list node for comments"); // reaplace with linked list building function;
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
		// ft_build(... , correspondent define);
		ft_printf("%s\n", "create a linked list node for ants data"); // reaplace with linked list building function;
		*read_detector = 1;
		return (1);
	}
}

int		ft_detect_command(char *str, int **command_detector) // add linked list methods;
{
	if ((str[0] == '#' && str[1] == '#') && ft_strequ(str, "##start"))
	{
		**command_detector = 1;
		// add linked list stuff
		ft_printf("%s\n", str);
		return (1);
	}
	else if ((str[0] == '#' && str[1] == '#') && ft_strequ(str, "##end"))
	{
		**command_detector = 2;
		//add linked list stuff;
		ft_printf("%s\n", str);

		return (1);
	}
	else if ((str[0] == '#' && str[1] == '#') && (!ft_strequ(str, "##start") && !ft_strequ(str, "##end")))
	{
		**command_detector = 3;
		//add linked list stuff;
		ft_printf("%s\n", str);

		return (1);
	}
	return (0);
}

int		ft_check_rooms(char *str, int *read_detector, int *command_detector) // if false with split change a status,  // add linked list methods;
{
	*read_detector = 1; //change this stuff;
	if (*command_detector == 0 && ft_detect_command(str, &command_detector))
		return (1);
	else if (*command_detector == 1) //ft_check_rooms_validity(str)
	{
		// add linked list stuff -> start;
		*command_detector = 0;
		return (1);
	}
	else if (*command_detector == 2) //ft_check_rooms_validity(str)
	{
		// add linked list stuff -> end;
		*command_detector = 0;
		return (1);
	}
	else if (*command_detector == 3) //ft_check_rooms_validity(str)
	{
		// add linked list stuff -> invalid command;
		*command_detector = 0; // pass it to a linked list and
		return (1);
	}
	else if (*command_detector == 0) //ft_check_rooms_validity(str)
	{
		// add linked list stuff -> invalid command;
		return (1);
	}
	return (0);
}

void	ft_validation(void)
{
	int 	read_detector;
	int		validity_detector;
	int		command_detector;
	char	*line;

	read_detector = 0;
	command_detector = 0;

	while (get_next_line(0, &line) == 1)
	{
		if (read_detector == 0)
			validity_detector = ft_ant_check(line, &read_detector);
		else if (read_detector == 1)
			validity_detector = ft_check_rooms(line, &read_detector, &command_detector);
		// else if (initial_data_set->read_detector == 2)
		// 	...
		if (validity_detector == 0)
		{
			ft_error_handler(read_detector);
			break ;
		}
		// if no links -> exit(0);
	}
	ft_printf("read_detector -> %d\n", read_detector);
}

int		main(void)
{
	//declaration of structure to store the initial data for the validator;
	//declare here a structure to save the valid lines;

	ft_validation(); //validation of the initial data set;
	// ft_buid_graph_and_data();
	// ft_printf("Read status -> %d\n", initial_data_set.read_detector);
	return (0);
}
