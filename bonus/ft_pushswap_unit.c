/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_unit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:16:17 by nicgonza          #+#    #+#             */
/*   Updated: 2024/01/02 12:16:21 by nicgonza         ###   ########.fr       */
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
