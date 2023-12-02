/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:26:46 by davgalle          #+#    #+#             */
/*   Updated: 2023/12/02 17:43:42 by davgalle         ###   ########.fr       */
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
//      printf("nodo a borrar: %i\n", aux->content);
		*a = aux->next;
//		printf("Valor a borrar: %i\n", aux->content);
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
	if (*a == NULL)
	{
		*a = new;
		new->next = NULL;
		return ;
	}
	if (ft_repeat_content(a, new->content))
	{
		ft_cleanlist(a);
//		printf("Contenido duplicado y borrado: %i\n", new->content);
		free (new);
//		printf("Nodo duplicado sin apilar NO liberada memoria: %i\n", new->content);
//		printf("Nodo duplicado sin apilar liberada memoria: Si\n");
		exit(1);
	}
	new->next = *a;
	*a = new;
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
//	printf("Contenido de un nuevo Nodo: %i\n", new->content);
	return (new);
}
