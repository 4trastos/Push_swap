/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:26:46 by davgalle          #+#    #+#             */
/*   Updated: 2023/12/04 20:34:58 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_repeat_content(t_stack_node **a, int content)
{
	t_stack_node	*aux;

	aux = *a;
	if (aux->content == content)
		return (1);
	while (aux->next != NULL)
	{
		if (aux->next->content == content)
			return (1);
		aux = aux->next;
	}
	return (0);
}

void	ft_stack_node(t_stack_node **a, t_stack_node *new)
{
	t_stack_node	*aux;

	aux = *a;
	if (*a == NULL)
	{
		*a = new;
		new->next = NULL;
		new->prev = NULL;
		return ;
	}
	if (ft_repeat_content(a, new->content))
	{
		ft_cleanlist(a);
		free (new);
		exit(1);
	}
	while (aux->next)
		aux = aux->next;
	aux->next = new;
	new->prev = aux; 
}

t_stack_node	*ft_create_node(int content)
{
	t_stack_node	*new;

	new = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
