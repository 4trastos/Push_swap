/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotatereverse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:31:43 by davgalle          #+#    #+#             */
/*   Updated: 2023/12/04 20:39:50 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_stack_node **a)
{
	int				last_content;
	t_stack_node	*aux;

	aux = *a;
	while (aux->next != NULL)
		aux = aux->next;
	last_content = aux->content;
	while (aux->prev != NULL)
	{
		aux->content = aux->prev->content;
		aux = aux->prev;
	}
	aux->content = last_content;
}

void	rra(t_stack_node **a)
{
	ft_reverse_rotate(a);
}

void	rrb(t_stack_node **b)
{
	ft_reverse_rotate(b);
}

