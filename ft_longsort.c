/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 11:50:36 by davgalle          #+#    #+#             */
/*   Updated: 2023/12/13 15:13:51 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_fivenodes(t_stack_node **a, t_stack_node **b)
{
	int	len;

	len = ft_stacklen(*a);
	ft_find_smaller(a);
	if (!ft_check_sort(*a))
	{
		if ((*a)->size == (*a)->position)
		{
			pb(b, a);
			ft_pushswapfour(a, b);
			pa(a, b);
		}
		if (!ft_check_sort(*a) && (*a)->position <= len / 2 && (*a)->content != (*a)->position)
		{
			if ((*a)->position <= len / 2)
				while ((*a)->prev == NULL)
					ra(a);
			else
				while ((*a)->prev == NULL)
					rra(a);
			pb(b, a);
			ft_pushswapfour(a, b);
			pa(a, b);
		}
	}
}

void	ft_sixnodes(t_stack_node **a, t_stack_node **b)
{
	int	len;

	len = ft_stacklen(*a);
	ft_find_smaller(a);
	while (!ft_check_sort(*a))
	{
		if ((*a)->size == (*a)->position)
		{
			pb(b, a);
			ft_fivenodes(a, b);
			pa(a, b);
		}
		if ((*a)->position <= len / 2 && (*a)->content != (*a)->position)
		{
			if ((*a)->position <= len / 2)
				while ((*a)->prev == NULL)
					ra(a);
			else
				while ((*a)->prev == NULL)
					rra(a);
			pb(b, a);
			ft_pushswapfour(a, b);
			pa(a, b);
		}
	}
}

void	ft_long_sort(t_stack_node **a, t_stack_node **b)
{
	int	len;
	len = ft_stacklen(*a);
	if (len == 5)
		ft_fivenodes(a, b);
	if (len == 6)
		ft_sixnodes(a, b);
	else if (len > 6)
		printf("Hay más de 6 números\n");
}
