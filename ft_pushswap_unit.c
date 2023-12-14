/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_unit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:02:24 by davgalle          #+#    #+#             */
/*   Updated: 2023/12/14 20:22:37 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	ft_find_smaller(t_stack_node **stack)
{
	t_stack_node	*aux;
	int	smaller;
	int	position;
	int i;

	i = ft_stacklen(*stack);
	aux = *stack;
	position = 0;
	smaller = aux->content;
	while (aux)
	{
		if (smaller > aux->content)
		{
			smaller = aux->content;
			position = aux->position;
		}
		aux = aux->next;
	}
	return (position);
}

t_stack_node	*ft_find_bigger(t_stack_node **a)
{
	int				i;
	t_stack_node	*big_node;
	t_stack_node	*aux;

	aux = *a;
	big_node = *a;
	i = INT_MIN;
	while (aux)
	{
		if (aux->content > i)
		{
			i = aux->content;
			big_node = aux;
		}
		aux = aux->next;
	}
	return (big_node);
}

