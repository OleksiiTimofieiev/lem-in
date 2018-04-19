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

void	ft_number_of_ants_check(t_g *initial_data_set)
{
	int i;
	char	*line;

	i = 0;
	get_next_line(0, &line);
	while (i < (int)ft_strlen(line))
	{
		if (ft_isdigit(line[i]))
			i++;
		else
		{
			ft_printf("%s\n", "ERROR");
			exit(0);
		}
	}
	initial_data_set->quantity_of_ants = ft_atoi(line);
}

void	ft_validation(t_g *initial_data_set)
{
	ft_number_of_ants_check(initial_data_set);
}


int		main(void)
{
	t_g initial_data_set; //declaration of structure to store the initial data for the validator;
	
	ft_validation(&initial_data_set); //validation of the initial data set;

	ft_printf("%d\n", initial_data_set.quantity_of_ants); //checing the function results;

	return (0);
}
