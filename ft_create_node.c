/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:10:50 by davgalle          #+#    #+#             */
/*   Updated: 2023/12/12 14:53:16 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checksort(t_stack_node *a)
{
	while (a->next != NULL)
	{
		if (a->content > a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}

void	ft_freelist(t_stack_node **a)
{
	t_stack_node	*aux;

	aux = *a;
	while (aux)
	{
		*a = aux->next;
		free (aux);
		aux = *a;
	}
	*a = NULL;
}

void	ft_cleanlist(t_stack_node **a)
{
	t_stack_node	*aux;

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

void	ft_stack_node(t_stack_node **a, t_stack_node *new)
{
	t_stack_node	*aux;
	int				position;

	position = 1;
	aux = *a;
	if (*a == NULL)
	{
		*a = new;
		new->next = NULL;
		new->prev = NULL;
		return ;
	}
	while (aux->next)
	{
		aux = aux->next;
		position++;
	}
	aux->next = new;
	new->prev = aux;
	aux->position = position;
}

t_stack_node	*ft_create_node(int content)
{
	t_stack_node	*new;

	new = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!new)
		return (NULL);
	new->content = content;
	new->size = 0;
	new->position = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
