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

#include "lem_in.h"

void	ft_number_of_ants_check(t_g *initial_data_set, char *str)
{
	int		i;

	i = 0;
	if (str[0] == '#' && str[1] == '#')
		return (0);
	else if (str[0] == '#')
	{
		ft_printf("%s\n", str);
		...
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
		initial_data_set->quantity_of_ants = ft_atoi(str);
		initial_data_set->read_status = 1;
		return (1);
	}
	return (0);
}



void	ft_validation(t_g *initial_data_set)
{
	char *line;

	line = NULL;
	initial_data_set->read_status = 0; // remove with static variable;

	// (get_next_line(0, &line) > 0 && (!has_char(&line, '-')))
	//  (ret && get_next_line(0, &line) > 0 && ft_strcmp(line, "") != 0)
	//	strsplit for the line;

	while (get_next_line(0, &line) == 1)
	{
		if (initial_data_set->read_status == 0)
			int i = ft_number_of_ants_check(initial_data_set, line); // detect a non valid line;
		// else if (initial_data_set->read_status == 1)
		// 	...
		// else if (initial_data_set->read_status == 2)
		// 	...
		if (i = 0)
		{

		}
	}
	// if (initial_data_set->read_status == 0) // maybe rework it with ret value;
	// 	ft_error();
	// if bool = 1 (if the file contained data) then nothing else print error
}

int		main(void)
{
	t_g initial_data_set; //declaration of structure to store the initial data for the validator;
	//declare here a structure to save the valid lines;

	ft_validation(&initial_data_set); //validation of the initial data set;
	ft_printf("Ants -> %d\n", initial_data_set.quantity_of_ants);
	// ft_printf("Read status -> %d\n", initial_data_set.read_status);
	return (0);
}
