/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotatereverse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:17:31 by nicgonza          #+#    #+#             */
/*   Updated: 2024/01/02 12:17:34 by nicgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_stack_node **a)
{
	t_stack_node	*first;
	t_stack_node	*prev;
	t_stack_node	*last;

	first = *a;
	prev = NULL;
	last = NULL;
	if (*a == NULL || (*a)->next == NULL)
		return ;
	while (first->next != NULL)
	{
		prev = first;
		first = first->next;
	}
	last = first;
	last->next = *a;
	*a = last;
	prev->next = NULL;
}

void	rra(t_stack_node **a)
{
	ft_reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b)
{
	ft_reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	write(1, "rrr\n", 4);
}
