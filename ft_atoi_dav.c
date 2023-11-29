/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_dav.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:57:43 by davgalle          #+#    #+#             */
/*   Updated: 2023/11/28 12:57:42 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count(char *str, int i)
{
	int	num;
	long long	result;

	result = 0;
	while (str[i] != '\0')
	{
		num = str[i] - '0';
		result = result * 10 + num;
		i++;
	}
	if (result > INT_MAX || result < INT_MIN)
		exit (1);
	return (result);
}

int	ft_atoi_dav(char *str)
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
	number = ft_count(str, i);
	return (number * z);
}
