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

// can be graph built: start &&end then do smthing;
// detect no input
// if no data -> exit -> test empty file
// ?display;
// after build delete and adjecency list;




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

void	ft_print_ll(t_init *data)
{
	while (data->prev)
		data = (data)->prev;
	while (data)
	{
		ft_printf("line->%s  type->%d\n", data->valid_line, data->type_of_the_line);
		data = data->next;
	}
}

int		main(void) // add build adjacency list method;
{
	t_init *initial_data; //keep the initial valid data;

	initial_data = NULL; //function init;

	ft_validation(&initial_data); //validation of the initial data set;

	ft_print_ll(initial_data);
	ft_printf("\n");
	ft_print_ll(initial_data);



	system ("leaks -q lem-in");
	return (0);
}
