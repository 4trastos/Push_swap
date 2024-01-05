/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_dav.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:57:43 by davgalle          #+#    #+#             */
/*   Updated: 2024/01/05 12:40:11 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_dav(char *str, int *status)
{
	int				i;
	int				result;
	long long int	nbr;

	nbr = 0;
	i = 0;
	result = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			result = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
		if (nbr > ((long long int)INT_MAX + 1) && result == -1)
			*status = 1;
		if (nbr > INT_MAX && result == 1)
			*status = 1;
	}
	return (nbr * result);
}
