/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 11:50:36 by davgalle          #+#    #+#             */
/*   Updated: 2023/12/14 20:15:52 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
void	ft_fivenodes(t_stack_node **a, t_stack_node **b)
{
	int	len;
	int min;

	len = ft_stacklen(*a);
	min = ft_find_smaller(a);
	if (!ft_check_sort(*a))
	{
		if (min == 0)
		{
			pb(b, a);
			ft_pushswapfour(a, b);
			pa(a, b);	
		}
		if (min != 0)
		{
			if (min <= len / 2)
			{
				while (min != 0)
				{
					ra(a);
					min--;
				}
			}
			if (min > len / 2)
			{
				min = len - min;
				while (min != 0)
				{
					rra(a);
					min--;
				}
			}
			pb(b, a);
			ft_pushswapfour(a, b);
			pa(a, b);
		}
	}
}*/

static int	ra_times(t_stack_node **a, int times)
{
	while (times--)
		ra(a);
	return (1);
}

static int	rra_times(t_stack_node **a, int times)
{
	while (times--)
		rra(a);
	return (1);
}

void	ft_fivenodes(t_stack_node **a, t_stack_node **b)
{
	int	len;
	int	min;

	len = ft_stacklen(*a);
	min = ft_find_smaller(a);

	if (!ft_check_sort(*a))
	{
		if (min == 0 || (min <= len / 2 && (ra_times(a, min) || 1))
			|| (min > len / 2 && (rra_times(a, len - min) || 1)))
		{
			pb(b, a);
			ft_pushswapfour(a, b);
			pa(a, b);
		}
	}
}

void	ft_sixnodes(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*aa;
	t_stack_node	*bb;

	bb = *b;
	aa = *a;
}

void	ft_long_sort(t_stack_node **a, t_stack_node **b)
{
	int	len;
	len = ft_stacklen(*a);
	if (len == 5)
		ft_fivenodes(a, b);
	if (len == 6)
		ft_sixnodes(a, b);
	else if (len > 6)
		printf("Hay más de 6 números\n");
}
