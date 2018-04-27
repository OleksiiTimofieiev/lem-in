/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 16:31:45 by otimofie          #+#    #+#             */
/*   Updated: 2018/04/21 16:46:14 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_isint(ssize_t nbr)
{
	ssize_t intmin;
	ssize_t intmax;

	intmin = -2147483648;
	intmax = 2147483647;
	if (nbr >= intmin && nbr <= intmax)
		return (1);
	return (0);
}
