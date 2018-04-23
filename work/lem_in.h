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

# define UNIV 1 // adhere to the linked list
# define ROOM 2 // adhere to the linked list
# define DATA_START 3 // adhere to the linked list
# define DATA_END 4 // adhere to the linked list
# define UNVALID_COMMAND 5
# define COMMENT 6
# define ANTS_QUANTITY 7
# define COMMAND 8



# define LINK 5 // adhere to the linked list

/*
**-----   data structure to keep the initial data set  -------------------------
*/

typedef struct			s_str_keeper
{
	int					type_of_the_line;
	char				*valid_line;
	struct s_str_keeper	*prev;
	struct s_str_keeper	*next;
}						t_str_keeper;

/*
**-------------------------   list of functions   ------------------------------
*/

#endif
