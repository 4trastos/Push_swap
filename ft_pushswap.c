/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:53:01 by davgalle          #+#    #+#             */
/*   Updated: 2023/12/10 12:43:12 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pushswapfour(t_stack_node **a, t_stack_node **b)
{
	int	first;
	int	second;
	int	third;
	int	four;

	while (!ft_checksort(*a))
	{
		first = (*a)->content;
		second = (*a)->next->content;
		third = (*a)->next->next->content;
		four = (*a)->next->next->next->content;
		if ((first > second && second < third && third < four)
			|| (first > second && second < third && third > four)
			|| (first > second && second > third && third > four))
			sa(a);
		if (first < second && second < third && third > four)
			rra(a);
		if (first < second && second > third && third < four)
			ra(a);
		else if ((first < second && second > third && third > four)
			|| (first > second && second > third && third < four))
		{
			pb(b, a);
			sa(a);
			pa(a, b);
		}
	}
}

void	ft_pushswapthree(t_stack_node **a)
{
	int	first;
	int	second;
	int	third;

	while (!ft_checksort(*a))
	{
		first = (*a)->content;
		second = (*a)->next->content;
		third = (*a)->next->next->content;
		if (first > second && first > third && second > third)
		{
			sa(a);
			rra(a);
		}
		if (first > second && first > third && second < third)
			ra(a);
		if (first > second && first < third)
			sa(a);
		if (first < second && first < third)
		{
			sa(a);
			ra(a);
		}
		else if (first < second && first > third)
			rra(a);
	}
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
