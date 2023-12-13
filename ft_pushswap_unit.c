/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_unit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:02:24 by davgalle          #+#    #+#             */
/*   Updated: 2023/12/13 14:40:37 by davgalle         ###   ########.fr       */
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

void	ft_find_smaller(t_stack_node **stack)
{
	t_stack_node	*aux;
	int	smaller;
	int value;

	if (!stack)
		return ;
	aux = *stack;
	value = 1;
	smaller = aux->content;
	while (aux)
	{
		if (smaller > aux->next->content)
			smaller = aux->next->content;
		aux = aux->next;
	}
	(*stack)->size = value;
}

void	ft_find_bigger(t_stack_node **stack)
{
	int	bigger;
	int	post;

	if (!stack)
		return ;
	bigger = (*stack)->content;
	post = 2;
	while (stack)
	{
		if (bigger < (*stack)->next->content)
		{
			bigger = (*stack)->next->content;
			post = (*stack)->next - *stack;
		}
		*stack = (*stack)->next;
	}
}

