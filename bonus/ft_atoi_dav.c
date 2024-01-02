/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_dav.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:57:43 by nicgonza          #+#    #+#             */
/*   Updated: 2024/01/02 12:12:10 by nicgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_dav(char *str, int *status)
{
	int				i;
	int				valorfinal;
	long long int	nbr;

	nbr = 0;
	i = 0;
	valorfinal = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			valorfinal = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
		if (nbr > ((long long int)INT_MAX + 1) && valorfinal == -1)
			*status = 1;
		if (nbr > INT_MAX && valorfinal == 1)
			*status = 1;
	}
	return (nbr * valorfinal);
}


/*static long int	ft_count(char *str, int i, int *status)
{
	int				num;
	long int		result;

	result = 0;
	while (str[i] != '\0')
	{
		num = str[i] - '0';
		result = result * 10 + num;
		i++;
	}
	if (result > INT_MAX || result < INT_MIN)
		*status = 1;
	return (result);
}

int	ft_atoi_dav(char *str, int *status)
{
	int	i;
	int	z;
	int	number;

	i = 0;
	z = 1;
	if (str[i] == '-')
	{
		z = -1;
		i++;
	}
	number = ft_count(str, i, status);
	return (number * z);
}*/
