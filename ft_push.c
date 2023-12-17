/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 08:45:32 by davgalle          #+#    #+#             */
/*   Updated: 2023/12/17 18:21:18 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*aux;

	aux = *src;
	if (*src == NULL)
		return ;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	aux->prev = NULL;
	if (*dst == NULL)
	{
		*dst = aux;
		aux->next = NULL;
	}
	else
	{
		aux->next = *dst;
		aux->next->prev = aux;
		*dst = aux;
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool checker)
{
	ft_push(a, b);
	if (!checker)
		write(1, "pa\n", 3);
}

void	pb(t_stack_node **b, t_stack_node **a, bool checker)
{
	ft_push(b, a);
	if (!checker)
		write(1, "pb\n", 3);
}
