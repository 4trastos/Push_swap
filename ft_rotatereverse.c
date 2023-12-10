/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotatereverse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 22:13:55 by davgalle          #+#    #+#             */
/*   Updated: 2023/12/10 12:40:19 by davgalle         ###   ########.fr       */
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
}

void	rrb(t_stack_node **b)
{
	ft_reverse_rotate(b);
}
