/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mass_ordering.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:28:49 by davgalle          #+#    #+#             */
/*   Updated: 2024/01/03 15:56:38 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_both(t_stack_node **a, t_stack_node **b,
			t_stack_node *faster_node)
{
	while (*a != faster_node->target_node
		&& *b != faster_node)
		rr(a, b);
	ft_center_position(*a);
	ft_center_position(*b);
}

void	ft_reverse_rotate_both(t_stack_node **a, t_stack_node **b,
			t_stack_node *faster_node)
{
	while (*a != faster_node->target_node
		&& *b != faster_node)
		rrr(a, b);
	ft_center_position(*a);
	ft_center_position(*b);
}

void	ft_finish_rotation(t_stack_node **stack, t_stack_node *top_node,
			char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->near_center)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->near_center)
				rb(stack);
			else
				rrb(stack);
		}
	}
}
