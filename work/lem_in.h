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

# define ANTS_QUANTITY 1
# define COMMENT 2
# define ROOM 3
# define LINK 4
# define COMMAND_START 5 // hope i`ll use it;
# define COMMAND_END 6 // hope i`ll use it;

/*
**-----   data structure to keep the initial data set  -------------------------
*/

typedef struct		s_str_keeper
{
	char			valid_line;
	int				type_of_the_line;
}					t_str_keeper;

/*
**-------------------------   list of functions   ------------------------------
*/

#endif
