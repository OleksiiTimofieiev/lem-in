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
# include "../ft_printf/ft_printf.h"

/*
**------------------------  type of the rooms  ---------------------------------
*/

# define ANTS_QUANTITY 1
# define UNVALID_COMMAND 2
# define COMMENT 3
# define VALID_COMMAND 4
# define ROOM 5
# define ROOM_START 6
# define ROOM_END 7
# define LINK 8

/*
**-----   data structure to keep the initial data set  -------------------------
*/

typedef struct			s_init
{
	int					type_of_the_line;
	char				*valid_line;
	struct s_init	*prev;
	struct s_init	*next;
}						t_init;

/*
**-------------------------   list of functions   ------------------------------
*/

t_init	*line_builder(char *valid_line, int i);
void			ft_list_builder(t_init **initial_data, char *valid_line, int i);
int			ft_ant_check(char *str, int *read_detector, t_init **initial_data);
int		ft_check_quantity(char *str); // delete with libft
int		ft_check_rooms(char *str, int *read_detector, int *command_detector, t_init **initial_data);


#endif
