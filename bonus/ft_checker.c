/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:26:06 by davgalle          #+#    #+#             */
/*   Updated: 2024/01/03 12:26:16 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checkarg(const char *s)
{
	int	i;
	int	neg;

	if (s[0] == '\0')
		return (1);
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
		if ((s[i] >= 32 && s[i] <= 47) || (s[i] >= 58 && s[i] <= 64)
			|| (s[i] >= 91 && s[i] <= 96) || (s[i] >= 123 && s[i] <= 126))
			return (1);
		i++;
	}
	if ((neg > 1) || (neg == 1 && s[0] != '-'))
		return (1);
	return (0);
}

int	ft_repeat_content(t_stack_node *a, int content)
{
	if (a == NULL)
		return (0);
	while (a->next != NULL)
	{
		if (a->content == content)
			return (1);
		a = a->next;
	}
	return (0);
}

int	ft_check_sort(t_stack_node *a)
{
	while (a->next != NULL)
	{
		if (a->content > a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}

int	ft_stacklen(t_stack_node *a)
{
	int					i;
	t_stack_node		*aux;

	i = 1;
	aux = a;
	while (aux->next != NULL)
	{
		aux = aux->next;
		i++;
	}
	if (i > 1)
		return (i);
	return (0);
}

bool	checksort(t_stack_node *a)
{
	if (a == NULL)
		return (1);
	while (a->next)
	{
		if (a->content > a->next->content)
			return (false);
		a = a->next;
	}
	return (true);
}
