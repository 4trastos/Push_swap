/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:59:47 by davgalle          #+#    #+#             */
/*   Updated: 2023/12/04 18:52:30 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack_node **a)
{
	int				first_content;
	t_stack_node	*aux;

	first_content = (*a)->content;
	aux = *a;
	while (aux->next != NULL)
	{
		aux->content = aux->next->content;
		aux = aux->next;
	}
	aux->content = first_content;
}

void	ra(t_stack_node **a)
{
	ft_rotate(a);
}

void	rb(t_stack_node **b)
{
	ft_rotate(b);
}
