/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ways_distribution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 11:15:31 by otimofie          #+#    #+#             */
/*   Updated: 2018/05/15 11:15:34 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_ways_distribution(void)
{
	int i;
	int j = 0;
	int ants_quantity = 10;
	
	int len[3] = {2, 3, 5};
	int	way[3] = {0, 0, 0};


		
		ft_printf("\n");


	while (ants_quantity)
	{
		i = 0;

					// ft_printf("i->%s%d%s\n", CYAN, i, RESET);


		if ((way[i] + 1) <= len[j])
		{
			ft_printf("len[j] --->%s%d%s\n", YELLOW, len[j], RESET);
			// ft_printf("j ->%d\n", j);

			// ft_printf("way[i] ->%d\n", way[i]);

			way[i] += 1;
			ants_quantity--;
					// ft_printf("\n");

		}
		else
		{
			i++;
			while (i < 3)
			{
					ft_printf("len[j]->%s%d%s\n", GREEN, len[j], RESET);
				// ft_printf("i ->%d\n", i);
				if ((way[i] + 1) <= len[j])
				{
					ft_printf("i->%s%d%s\n", RED, i, RESET);

					ft_printf("way[i]->%s%d%s\n", RED, way[i], RESET);

					way[i] += 1;
					ft_printf("way[i]->%s%d%s\n", RED, way[i], RESET);
		ants_quantity--;


					break;
				}
				i++;
					
			}
					if (i > j)
						j++;
					// ft_printf("j->%s%d%s\n", GREEN, j, RESET);
			
					ft_printf("\n");
			
		}
	}
	int b = 0;
	while (b < 3)
	{
		ft_printf("%d\n", way[b]);
		b++;
	}
}
