/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:25:23 by davgalle          #+#    #+#             */
/*   Updated: 2024/01/03 15:55:50 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker(t_stack_node *a)
{
	if (ft_check_sort(a) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
