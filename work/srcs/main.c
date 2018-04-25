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

//can be graph built: start &&end then do smthing;
// if no data -> exit -> test empty file
// ?display;
//after build delete and adjecency list;



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

	initial_data = NULL; //function init;

	ft_validation(&initial_data); //validation of the initial data set;

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
