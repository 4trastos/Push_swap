/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:26:46 by davgalle          #+#    #+#             */
/*   Updated: 2023/11/29 19:50:41 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_cleanlist(t_stack_node **a)
{
    t_stack_node    *aux;

    aux = *a;
    while (aux)
    {
        printf("nodo a borrar: %i\n", aux->content);
        *a = aux->next;
		printf("Valor a borrar: %i\n", aux->content);
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
/*
int	ft_print_content(t_stack_node *a)
{
	int		i;
	t_stack_node	*aux;

	i = 1;
	if (!a)
		return (0);
	aux = a;
	while (aux->next != NULL)
	{
		aux = aux->next;
		i++;
	}
//	printf("Numero de Nodos: %i\n", i);
	return (i);
}*/

void	ft_stack_node(t_stack_node **a, t_stack_node *new)
{
	if (*a == NULL)
	{
		*a = new;
		new->next = NULL;
		return ;
	}
	new->next = *a;
	if (ft_repeat_content(a, new->content))
	{
		ft_cleanlist(a);
		printf("Contenido duplicado y borrado: %i\n", new->content);
		exit(1);
	}
	*a = new;
/*	if (ft_repeat_content(a, new->content))
	{
		ft_cleanlist(a);
		printf("Contenido duplicado y borrado: %i\n", new->content);
	}*/
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
