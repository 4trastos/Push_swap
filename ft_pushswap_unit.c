/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_unit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:02:24 by davgalle          #+#    #+#             */
/*   Updated: 2023/12/17 17:26:44 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*ft_return_faster(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->faster)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

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

t_stack_node	*ft_find_smaller(t_stack_node **stack)
{
	t_stack_node	*smaller;
	t_stack_node	*aux;
	int				i;

	i = INT_MAX;
	aux = *stack;
	smaller = *stack;
	while (aux)
	{
		if (aux->content < i)
		{
			i = aux->content;
			smaller = aux;
		}
		aux = aux->next;
	}
	return (smaller);
}

int	ft_find_small(t_stack_node **stack)
{
	t_stack_node	*aux;
	int				smaller;
	int				position;
	int				i;

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

t_stack_node	*ft_find_bigger(t_stack_node **stack)
{
	int				i;
	t_stack_node	*biggest;
	t_stack_node	*aux;

	aux = *stack;
	biggest = *stack;
	i = INT_MIN;
	while (aux)
	{
		if (aux->content > i)
		{
			i = aux->content;
			biggest = aux;
		}
		aux = aux->next;
	}
	return (biggest);
}
