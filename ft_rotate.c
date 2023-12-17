/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 22:11:05 by davgalle          #+#    #+#             */
/*   Updated: 2023/12/17 18:26:30 by davgalle         ###   ########.fr       */
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

void	ra(t_stack_node **a, bool checker)
{
	ft_rotate(a);
	if (!checker)
		write(1, "ra\n", 3);
}

void	rb(t_stack_node **b, bool checker)
{
	ft_rotate(b);
	if (!checker)
		write(1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b, bool checker)
{
	ft_rotate(a);
	ft_rotate(b);
	if (!checker)
		write(1, "rr\n", 3);
}

void	ss(t_stack_node **a, t_stack_node **b, bool checker)
{
	ft_swap(a);
	ft_swap(b);
	if (!checker)
		write(1, "ss\n", 3);
}
