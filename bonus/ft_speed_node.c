/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_speed_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:17:59 by nicgonza          #+#    #+#             */
/*   Updated: 2024/01/02 12:18:03 by nicgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_center_position(t_stack_node *stack)
{
	int	i;
	int	center;

	i = 0;
	if (!stack)
		return ;
	center = ft_stacklen(stack) / 2;
	while (stack)
	{
		stack->position = i;
		if (i <= center)
			stack->near_center = true;
		else
			stack->near_center = false;
		stack = stack->next;
		++i;
	}
}

void	ft_target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*aux;
	t_stack_node	*target_node;
	long			best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		aux = a;
		while (aux)
		{
			if (aux->content > b->content
				&& aux->content < best_match_index)
			{
				best_match_index = aux->content;
				target_node = aux;
			}
			aux = aux->next;
		}
		if (LONG_MAX == best_match_index)
			b->target_node = ft_find_smaller(&a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	ft_speed(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_stacklen(a);
	len_b = ft_stacklen(b);
	while (b)
	{
		b->speed = b->position;
		if (!(b->near_center))
			b->speed = len_b - (b->position);
		if (b->target_node->near_center)
			b->speed += b->target_node->position;
		else
			b->speed += len_a - (b->target_node->position);
		b = b->next;
	}
}

void	ft_faster(t_stack_node *b)
{
	long			best_match_speed;
	t_stack_node	*best_match_node;

	if (!b)
		return ;
	best_match_speed = LONG_MAX;
	while (b)
	{
		if (b->speed < best_match_speed)
		{
			best_match_speed = b->speed;
			best_match_node = b;
		}
		b = b->next;
	}
	best_match_node->faster = true;
}

void	ft_speed_nodes(t_stack_node *a, t_stack_node *b)
{
	ft_center_position(a);
	ft_center_position(b);
	ft_target_node(a, b);
	ft_speed(a, b);
	ft_faster(b);
}
