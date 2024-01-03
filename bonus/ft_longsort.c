/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:27:25 by davgalle          #+#    #+#             */
/*   Updated: 2024/01/03 15:56:30 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stackfive(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*smaller;

	while (!ft_checksort(*a))
	{
		smaller = ft_find_smaller(a);
		if (*a == smaller)
			pb(b, a);
		if ((*a)->next == smaller)
		{
			ra(a);
			pb(b, a);
		}
		else if ((*a)->next->next == smaller
			|| (*a)->next->next->next == smaller
			|| (*a)->next->next->next->next == smaller)
		{
			while (*a != smaller)
				rra(a);
		}
		ft_stackfour(a, b);
	}
	pa(a, b);
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
	while (len > 3)
	{
		pb(b, a);
		len--;
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
