/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:35:26 by davgalle          #+#    #+#             */
/*   Updated: 2023/11/19 11:41:26 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include<stdio.h>
#include<unistd.h>
#include<string.h>

void	ft_putarg(char arg[])
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		i++;
	}
	write(1, arg, i);
}

