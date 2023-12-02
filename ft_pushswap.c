/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:36:59 by davgalle          #+#    #+#             */
/*   Updated: 2023/12/02 19:39:42 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*int	ft_pushswap(t_stack_node **a)
{
	t_stack_node	*aux;

	aux = *a;
	return (1);
}*/
/*
void	ft_swap(t_stack_node **a)
{
	t_stack_node	*aux;

	if (*a == NULL || (*a)->next == NULL)
		return;
	aux = (*a)->next;
	(*a)->next = (*a)->prev;
	(*a)->prev = aux;
	((*a)->next)->next = *a;
	((*a)->next)->prev = NULL;
	*a = (*a)->prev;
}*/
void	ft_swap_content(t_stack_node *node1, t_stack_node *node2)
{
	printf("Node 1 antes de Swap: %i\n", node1->content);
    int	temp;

	temp = node1->content;
    node1->content = node2->content;
    node2->content = temp;
	printf("Node1 despues del swap: %i\n", node1->content);
}

void	ft_swap(t_stack_node **a)
{
	if (*a == NULL || (*a)->next == NULL)
		return ;
	ft_swap_content(*a, (*a)->next);
}
/*
void ft_swap(t_stack_node **a)
{
    if (*a != NULL && (*a)->next != NULL)
	{
		printf("antes del swap Nodo1: %i\n", (*a)->content);
        int temp;
		
		temp = (*a)->content;
        (*a)->content = (*a)->next->content;
        (*a)->next->content = temp;
		printf("después del swap Nodo1: %i\n", (*a)->content);
    }
}*/

void	sa(t_stack_node **a)
{
	ft_swap(a);
//	ft_pushswap(a);
}

void	sb(t_stack_node **b)
{
	ft_swap(b);
//	ft_pushswap(b);
}
