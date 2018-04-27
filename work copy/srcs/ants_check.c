/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 12:33:56 by otimofie          #+#    #+#             */
/*   Updated: 2018/04/25 12:34:00 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	int	ant_check_helper(char *str)
{
	int		i;

	i = 0;
	if (!ft_strlen(str) || ft_strlen(str) < 1 || ft_strlen(str) > 10)
		return (0);
	while (i < (int)ft_strlen(str))
	{
		if (ft_isdigit(str[i]) && ft_atoi(&str[0]) != 0)
			i++;
		else
			return (0);
	}
	return (1);
}

int			ft_ant_check(char *str, int *read_detector, t_init **initial_data)
{
	if (str[0] == '#' && str[1] == '#'
		&& (!ft_strequ(str, "##start") && !ft_strequ(str, "##end")))
	{
		ft_list_builder(initial_data, str, UNVALID_COMMAND);
		return (1);
	}
	else if (str[0] == '#' && str[1] != '#')
	{
		ft_list_builder(initial_data, str, COMMENT);
		return (1);
	}
	else
	{
		if (!ant_check_helper(str))
			return (0);
		ft_list_builder(initial_data, str, ANTS_QUANTITY);
		*read_detector = 1;
		return (1);
	}
	return (0);
}
