/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mass_ordering.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:29:39 by davgalle          #+#    #+#             */
/*   Updated: 2023/12/16 17:05:32 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

 void	ft_rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *faster_node)
{
	while (*a != faster_node->target_node
		&& *b != faster_node)
		rr(a, b);
	ft_center_position(*a);
	ft_center_position(*b);
}

void	ft_reverse_rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *faster_node)
{
	while (*a != faster_node->target_node
		&& *b != faster_node)
		rrr(a, b);
	ft_center_position(*a);
	ft_center_position(*b);
}

void	ft_finish_rotation(t_stack_node **stack, t_stack_node *top_node, char stack_name)
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
