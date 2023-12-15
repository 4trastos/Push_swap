/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 11:50:36 by davgalle          #+#    #+#             */
/*   Updated: 2023/12/15 22:34:32 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	min = ft_find_small(a);

	if (!ft_check_sort(*a))
	{
		if (min == 0 || (min <= len / 2 && (ra_times(a, min) || 1))
			|| (min > len / 2 && (rra_times(a, len - min) || 1)))
		{
			pb(b, a);
			ft_stackfour(a, b);
			pa(a, b);
		}
	}
}

void	ft_long_sort(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*smaller;
	int	len;

	len = ft_stacklen(*a);
	if (len == 5)
		ft_fivenodes(a, b);
	else
	{
		while (len_a-- > 3)
			pb(b, a);
	}
	ft_stackthree(a);
	while (*b)
	{
		ft_speed_groups(*a, *b);
		move_nodes(a, b);
	}
	set_current_position(*a);
	smaller = ft_find_smaller(*a);
	if (smaller->above_median)
		while (*a != smaller)
			ra(a);
	else
		while (*a != smaller)
			rra(a);
}


