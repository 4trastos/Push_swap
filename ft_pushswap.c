/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:36:59 by davgalle          #+#    #+#             */
/*   Updated: 2023/12/05 12:40:39 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pushswap(t_stack_node **a, int *len)
{
	int	first;
	int second;
	int	third;
	int x;

	first = (*a)->content;
	second = (*a)->next->content;
	third = (*a)->next->next->content;
	x = *len;
	if (*a == NULL || (*a)->next == NULL)
		return ;
	while (!ft_checksort(*a))
	{
		if (first > second && first > third)
		{
			if (second < first && second > third)
			{
				sa(a);
				rra(a);
			}
			if (second < first && second < third)
				ra(a);
		}
		if (first > second && first < third)
		{
			if (second < first && second < third)
				sa(a);
		}
		else if (first < second && second > third)
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
