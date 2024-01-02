/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:17:11 by nicgonza          #+#    #+#             */
/*   Updated: 2024/01/02 12:17:14 by nicgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack_node **a)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (*a != NULL && (*a)->next != NULL)
	{
		first = *a;
		*a = first->next;
		last = first;
		while (last->next != NULL)
		{
			last = last->next;
		}
		last->next = first;
		first->next = NULL;
	}
}

void	ra(t_stack_node **a)
{
	ft_rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack_node **b)
{
	ft_rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	ft_rotate(a);
	ft_rotate(b);
	write(1, "rr\n", 3);
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	ft_swap(a);
	ft_swap(b);
	write(1, "ss\n", 3);
}
