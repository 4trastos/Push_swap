/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:26:46 by davgalle          #+#    #+#             */
/*   Updated: 2023/11/28 19:54:23 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_repeat_content(t_stack_node *lst, t_stack_node *new)
{
	t_stack_node	*crazy;

	crazy = lst;
	while (crazy->next != NULL)
	{
		if (crazy->content == new->content)
//			return (1);
			printf("Número repetido real: %i\n", crazy->content);
		crazy = crazy->next;
		if (crazy->content == new->content)
			printf("Númwero repetido real: %i\n", crazy->content);
	}
	return (0);
}

int	ft_print_content(t_stack_node *lst)
{
	int		i;
	t_stack_node	*aux;

	i = 1;
	if (!lst)
		return (0);
	aux = lst;
	while (aux->next != NULL)
	{
		aux = aux->next;
		i++;
	}
	printf("Numero de Nodos: %i\n", i);
	return (i);
}

void	ft_stack_node(t_stack_node **a, t_stack_node *new)
{
	if (*a == NULL)
	{
		*a = new;
		new->next = NULL;
		return ;
	}
//	if (*a->content == new->content)
//		printf("Repetido coño!!!: %\n", *a->content);
	if (ft_repeat_content(*a, new))
		printf("Número repetidoi\n");
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
	printf("Contenido de un  Nodo: %i\n", new->content);
	return (new);
}
