/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 12:50:13 by otimofie          #+#    #+#             */
/*   Updated: 2018/03/23 12:50:15 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "./ft_printf/ft_printf.h"

/*
**-----------------   ADT to save the data on the input   ----------------------
*/

typedef struct		s_read
{
	char			*line;
	struct s_read	*next;
}					t_read;

typedef	struct 		s_data
{
	t_read			*initial_information;
}					t_data;

#endif
