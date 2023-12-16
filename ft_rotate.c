/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 22:11:05 by davgalle          #+#    #+#             */
/*   Updated: 2023/12/16 17:40:18 by davgalle         ###   ########.fr       */
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
}

void	rb(t_stack_node **b)
{
	ft_rotate(b);
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	ft_rotate(a);
	ft_rotate(b);
}
