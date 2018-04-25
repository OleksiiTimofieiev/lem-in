/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_core.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 14:01:15 by otimofie          #+#    #+#             */
/*   Updated: 2018/04/25 14:01:17 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_validation(t_init **initial_data)
{
	int		r_det;
	int		validity_detector;
	int		c_d[3];
	char	*line;

	r_det = 0;
	c_d[0] = 0;
	c_d[1] = 0;
	c_d[2] = 0;
	while (get_next_line(0, &line) == 1)
	{
		if (r_det == 0)
			validity_detector = ft_ant_check(line, &r_det, initial_data);
		else if (r_det == 1)
			validity_detector = ft_check_rooms(line, &r_det, c_d, initial_data);
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
