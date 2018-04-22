/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:51:17 by otimofie          #+#    #+#             */
/*   Updated: 2018/04/18 12:51:19 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**------------------------  runtime declarations  ------------------------------
*/

#ifndef LEM_IN_H
# define LEM_IN_H
# include "./ft_printf/ft_printf.h"

/*
**------------------------  type of the rooms  ---------------------------------
*/

# define ANTS_QUANTITY 1 // adhere to the linked list
# define COMMAND_START 2 // hope i`ll use it;
// add unvalid command
# define COMMAND_END 3 // hope i`ll use it;
# define COMMENT 4 // adhere to the linked list
# define ROOM 5 // adhere to the linked list
# define LINK 6 // adhere to the linked list

/*
**-----   data structure to keep the initial data set  -------------------------
*/

typedef struct			s_str_keeper
{
	int					type_of_the_line;
	char				*valid_line;
	struct s_str_keeper	*next;
}						t_str_keeper;

/*
**-------------------------   list of functions   ------------------------------
*/

#endif
