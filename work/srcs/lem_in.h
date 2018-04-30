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
**------------------------  type of the initial data  --------------------------
*/

# define ANTS_QUANTITY 1
# define UNVALID_COMMAND 2
# define COMMENT 3
# define VALID_COMMAND 4
# define ROOM 5
# define ROOM_START 6
# define ROOM_END 7
# define LINK 8
# define SKIP 9

/*
**-----   data structure to keep the initial data set  -------------------------
*/

typedef struct			s_init
{
	int					type_of_the_line;
	char				*valid_line;
	struct s_init		*prev;
	struct s_init		*next;
}						t_init;

/*
**---------------------------   graph data structure  --------------------------
*/

typedef struct			s_edge
{
	char				*name_of_the_connected_room;
	struct s_edge		*next;
}						t_edge;

typedef struct			s_vertex
{
	char				*vertex_name;
	struct s_edge		*e_next;
	struct s_vertex		*v_next;
}						t_vertex;

/*
**-------------------------   list of functions for validation  ----------------
*/

void					ft_validation(t_init **initial_data);
int						ft_ant_check(char *str, int *r, t_init **it);
int						ft_check_rooms(char *s, int *r, int *c, t_init **i);
int						ft_aspects(char *str, t_init *initial_data);
int						ft_exclusions(t_init *initial_data);
int						ft_detect_command(char *str, int *c_det);
int						ft_det_line(char *str, int **c_det);
int						ft_check_links(char *str, t_init **initial_data);
void					ft_list_builder(t_init **i, char *v, int iq);
t_init					*line_builder(char *valid_line, int i);
void					ft_detect_input(t_init *initial_data);

/*
**-------------------------   list of functions to build a graph  --------------
*/

void					ft_build_vertex_structure(t_init *initial_data, t_vertex **vertex);

#endif
