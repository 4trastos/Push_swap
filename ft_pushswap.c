/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:53:01 by davgalle          #+#    #+#             */
/*   Updated: 2023/12/16 23:15:50 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stackfour(t_stack_node **a, t_stack_node **b)
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
			|| (*a)->next->next->next == smaller)
		{
			while (*a != smaller)
				rra(a);
		}
		ft_stackthree(a);
	}
	while (*b)
		pa(a, b);
}

void	ft_stackthree(t_stack_node **a)
{
	t_stack_node	*biggest;

	biggest = ft_find_bigger(a);
	if (*a == biggest)
		ra(a);
	else if ((*a)->next == biggest)
		rra(a);
	if ((*a)->content > (*a)->next->content)
		sa(a);
}

void	ft_swap(t_stack_node **a)
{
	int	temp;

	if (*a != NULL && (*a)->next != NULL)
	{
		temp = (*a)->content;
		(*a)->content = (*a)->next->content;
		(*a)->next->content = temp;
	}
}

void	sa(t_stack_node **a)
{
	ft_swap(a);
/*	if (!check)
		write(1, "sa\n", 3);*/
}

void	sb(t_stack_node **b)
{
	ft_swap(b);
/*	if (!check)
		write(1, "sb\n", 3);*/
}
