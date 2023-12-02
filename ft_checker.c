/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:37:20 by davgalle          #+#    #+#             */
/*   Updated: 2023/12/02 17:29:11 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_arguments(char *s)
{
	int	i;
	int	neg;

	i = 0;
	neg = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '-')
			neg++;
		if (s[i] == '-' && s[i + 1] >= '1' && s[i + 1] <= '9')
			i++;
		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
			return (1);
		if (s[i] == '\\' && s[i + 1] >= '1' && s[i + 1] <= '9')
			return (1);
		if ((s[i] >= 32 && s[i] <= 47) || (s[i] >= 58 && s[i] <= 64))
			return (1);
		if ((s[i] >= 91 && s[i] <= 96) || (s[i] >= 123 && s[i] <= 126))
			return (1);
		i++;
	}
	if ((neg > 1) || (neg == 1 && s[0] != '-'))
		return (1);
	return (0);
}

int	ft_stacklen(t_stack_node *stack)
{
	int				i;
	t_stack_node	*aux;

	i = 1;
	aux = stack;
	while (aux->next != NULL)
	{
		aux = aux->next;
		i++;
	}
	if (i > 1)
		return (i);
	return (0);
}

int	ft_checksort(t_stack_node *a)
{
	t_stack_node	*aux;

	aux = a;
	while (aux != NULL && aux->next != NULL)
	{
		if (aux->content < aux->next->content)
			return (0);
		aux = aux->next;
	}
	return (1);
}
