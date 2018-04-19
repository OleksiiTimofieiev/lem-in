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

void	ft_error(void)
{
	ft_printf("%s\n", "ERROR");
	exit(0);
}

void	ft_number_of_ants_check(t_g *initial_data_set, char *str)
{
	int		i;

	i = 0;
	if (str[0] == '#' && str[1] == '#')
		ft_error();
	else if (str[0] == '#')
		DO_NOTHING;
	else
	{
		if (!ft_strlen(str) || ft_strlen(str) < 1 || ft_strlen(str) > 10)
			ft_error();
		while (i < (int)ft_strlen(str))
			if (ft_isdigit(str[i]) && ft_atoi(&str[0]) != 0)
				i++;
			else
				ft_error();
		initial_data_set->quantity_of_ants = ft_atoi(str);
		initial_data_set->read_status = 1;
		ft_printf("Ants -> %d\n", initial_data_set->quantity_of_ants);
	}
}

void	ft_validation(t_g *initial_data_set)
{
	char *line;

	line = NULL;
	initial_data_set->read_status = 0; // remove with static variable;

	// (get_next_line(0, &line) > 0 && (!has_char(&line, '-')))
	//  (ret && get_next_line(0, &line) > 0 && ft_strcmp(line, "") != 0)

	while (get_next_line(0, &line))
	{
		if (initial_data_set->read_status == 0)
			ft_number_of_ants_check(initial_data_set, line);
		// else if (initial_data_set->read_status == 1)
		// 	...
		// else if (initial_data_set->read_status == 2)
		// 	...
	}
	if (initial_data_set->read_status == 0)
		ft_error();
	// if bool = 1 (if the file contained data) then nothing else print error
}

int		main(void)
{
	t_g initial_data_set; //declaration of structure to store the initial data for the validator;

	ft_validation(&initial_data_set); //validation of the initial data set;
	// ft_printf("Read status -> %d\n", initial_data_set.read_status);
	return (0);
}
