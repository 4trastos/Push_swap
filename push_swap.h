/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:35:51 by davgalle          #+#    #+#             */
/*   Updated: 2023/11/21 15:17:54 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H 

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct s_stack_node
{
	int		value;							// el valor asociado al nodo
	int		current_positoin;				// la posición actual del nodo.
	int		final_index;					// el índice final asociado al nodo.
	int		push_price;						// el precio asociado al nodo.
	bool	above_median;					// indica si el nodo está por encima de la mediana.
	bool	cheapest;						// indica si el nodo es el más económico.
	struct	s_stack_node	*target_node;	// Un puntero a otro nodo que es el objetivo asociado a este nodo.
	struct	s_stack_node	*next;			// Un puntero al siguiente nodo en la pila.
	struct	s_stack_node	*prev;			// Un puntero al nodo anterior en la pila.
}	t_stack_node;

#define MAX_ARGS 100

//*** handled inputs ./push_swap "1 -42 1337" ***
 
char	**ft_split(char const *s, char c);

//*** handled errors-free ***


//*** Stack creation ***


//*** linked list utils ***


//*** Algorithms ***


//*** Commands ***

void	sa(t_stack_node **a, bool checker);						// swap_command.c	
void	sb(t_stack_node **b, bool checker);						// swap_command.c
void	ss(t_stack_node **a, t_stack_node **b, bool checker);
void	pa(t_stack_node **a, t_stack_node **b, bool checker);
void	pb(t_stack_node **a, t_stack_node **b, bool checker);
void	ra(t_stack_node **a, bool checker);
void	rb(t_stack_node **b, bool checker);
void	rr(t_stack_node **a. t_stack_node **b, bool checker);
void	rra(t_stack_node **a, bool checker);
void	rrb(t_stack_node **b, bool checker);
void	rrr(t_stack_node **a, t_stack_node **b, bool checker);

#endif
