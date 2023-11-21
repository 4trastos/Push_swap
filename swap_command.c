/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:59:19 by davgalle          #+#    #+#             */
/*   Updated: 2023/11/21 15:35:25 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack_node **a, bool checker)
{
	if (*a == NULL || (*a)->next == NULL)
		return;
	t_stack_node *first = *a;
	t_stack_node *second = (*a)->next;

	first->next = second->next;
	second->next = first;
	*a = second;
	if (checker)
	{

	}
}
