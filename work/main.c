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

int		ft_number_of_ants_check(char *str, int *read_status)
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
		*read_status = 1;
		return (1);
	}
	return (0);
}



void	ft_validation(void)
{
	int 	read_status;
	int		validity_detector;
	char	*line;

	read_status = 0;
	while (get_next_line(0, &line) == 1)
	{
		if (read_status == 0)
			validity_detector = ft_number_of_ants_check(line, &read_status);
		else if (read_status == 1)
			ft_printf("%s\n", "asdfasdfasdf");
		// else if (initial_data_set->read_status == 2)
		// 	...
		if (validity_detector == 0)
		{
			ft_printf("%s\n", "ERROR");
			break;
		}
	}


	ft_printf("Read_status -> %d\n", read_status);
}

int		main(void)
{
	//declaration of structure to store the initial data for the validator;
	//declare here a structure to save the valid lines;

	ft_validation(); //validation of the initial data set;
	// ft_buid_graph_and_data();
	// ft_printf("Read status -> %d\n", initial_data_set.read_status);
	return (0);
}
