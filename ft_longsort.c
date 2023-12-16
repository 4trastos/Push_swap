/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 11:50:36 by davgalle          #+#    #+#             */
/*   Updated: 2023/12/16 23:17:24 by davgalle         ###   ########.fr       */
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

void	ft_move_nodes(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*faster_node;

	faster_node = ft_return_faster(*b);
	if (faster_node->near_center
		&& faster_node->target_node->near_center)
		ft_rotate_both(a, b, faster_node);
	else if (!(faster_node->near_center)
		&& !(faster_node->target_node->near_center))
		ft_reverse_rotate_both(a, b, faster_node);
	ft_finish_rotation(b, faster_node, 'b');
	ft_finish_rotation(a, faster_node->target_node, 'a');
	pa(a, b);
}

void	ft_long_sort(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*smaller;
	int				len;

	len = ft_stacklen(*a);
	if (len == 5)
		ft_fivenodes(a, b);
	else
	{
		while (len-- > 3)
			pb(b, a);
	}
	ft_stackthree(a);
	while (*b)
	{
		ft_speed_nodes(*a, *b);
		ft_move_nodes(a, b);
	}
	ft_center_position(*a);
	smaller = ft_find_smaller(a);
	if (smaller->near_center)
		while (*a != smaller)
			ra(a);
	else
		while (*a != smaller)
			rra(a);
}
