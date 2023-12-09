/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:10:50 by davgalle          #+#    #+#             */
/*   Updated: 2023/12/09 20:42:41 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checksort(stack_node *a)
{
	while (a->next != NULL)
	{
		if (a->content > a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}

void	ft_freelist(stack_node **a)
{
	stack_node	*aux;

	aux = *a;
	while (aux)
	{
		*a = aux->next;
		free (aux);
		aux = *a;
	}
	*a = NULL;
}

void	ft_cleanlist(stack_node **a)
{
	stack_node	*aux;

	aux = *a;
	while (aux)
	{
		*a = aux->next;
		free (aux);
		aux = *a;
	}
	*a = NULL;
	write(1, "Error", 5);
	write(1, "\n", 1);
}

void	ft_stack_node(stack_node **a, stack_node *new)
{
	stack_node	*aux;

	aux = *a;
	if (*a == NULL)
	{
		*a = new;
		new->next = NULL;
		new->prev = NULL;
		return ;
	}
/*	if (ft_repeat_content(a, new->content))
	{
		ft_cleanlist(a);
		free (new);
	}*/
	while (aux->next)
		aux = aux->next;
	aux->next = new;
	new->prev = aux;
}

stack_node	*ft_create_node(int content)
{
	stack_node	*new;

	new = (stack_node *)malloc(sizeof(stack_node));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
