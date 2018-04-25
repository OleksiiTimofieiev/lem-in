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

void	ft_validation(t_init **initial_data)
{
	int		r_det;
	int		validity_detector;
	int		command_detector[3];
	char	*line;

	r_det = 0;
	command_detector[0] = 0;
	command_detector[1] = 0;
	command_detector[2] = 0;
	while (get_next_line(0, &line) == 1)
	{
		if (r_det == 0)
			validity_detector = ft_ant_check(line, &r_det, initial_data);
		else if (r_det == 1)
			validity_detector = ft_check_rooms(line, &r_det, command_detector, initial_data);
		else if (r_det == 2)
			validity_detector = ft_check_links(line, initial_data);
		if (validity_detector == 0)
		{
			free(line);
			ft_printf("%s\n", "ERROR");
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
