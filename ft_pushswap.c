/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:36:59 by davgalle          #+#    #+#             */
/*   Updated: 2023/12/05 20:08:16 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pushswapfour(t_stack_node **a, t_stack_node **b)
{
	int	first;
	int second;
	int	third;
	int four;

	first = (*a)->content;
	second = (*a)->next->content;
	third = (*a)->next->next->content;
	four = (*a)->next->next->next->content;
	while (!ft_checksort(*a))
	{
		if (first < second && second > third && third < four)
			ra(a);
		if ((first > second && second < third && third < four) || 
				(first > second && second > third && third < four) || 
				(first < second && second < third && third > four))
			ra(a);
		if ((first > second && second > third && third > four) ||
				(first > second && second < third && third > four))
			sa(a);
		if ((first < second && second > third && third > four) || 
				(first < second && second > third && third > four))
		{
			pb(a, b);
			pb(a, b);
		}
	}
}

void	ft_pushswapthree(t_stack_node **a)
{
	int	first;
	int second;
	int	third;

	first = (*a)->content;
	second = (*a)->next->content;
	third = (*a)->next->next->content;
	while (!ft_checksort(*a))
	{
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

void ft_swap(t_stack_node **a)
{
    if (*a != NULL && (*a)->next != NULL)
	{
        int temp;
		
		temp = (*a)->content;
        (*a)->content = (*a)->next->content;
        (*a)->next->content = temp;
    }
}

void	sa(t_stack_node **a)
{
	ft_swap(a);
}

void	sb(t_stack_node **b)
{
	ft_swap(b);
}
