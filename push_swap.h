/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:34:28 by davgalle          #+#    #+#             */
/*   Updated: 2023/12/09 20:47:44 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H	
# define PUSH_SWAP_H

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack_node
{
	int					content;
	int					posittion;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	stack_node;

//*** startup algorithms ***

int		main(int argc, char **argv);
void	ft_partone(stack_node **a, char **argv, int	argc);

//*** create content nodes ***

char	**ft_split(const char *str, char c);
int		ft_atoi_dav(char *str, int *status);

//*** auxiliary functions ***

bool			stack_sorted(stack_node *stack);

//*** create nodes ***

stack_node	*ft_create_node(int content);
void	ft_stack_node(stack_node **a, stack_node *new);

//*** checker ***

int		ft_checkarg(const char *s);
int		ft_checksort(stack_node *a);
int		ft_repeat_content(stack_node *a, int content);

//*** errros ***

void	ft_free_string(char **str);
void	ft_free_argv(char **argv);
void	ft_error(stack_node **a, char **argv, bool check_argc);
void	ft_free_stack(stack_node **a);

//*** sort stack ***

void	ft_sort_stack(stack_node **a);

//*** movement swap ***


//*** movement push ***

//*** movement rotate ***


//*** movement reverse ***


#endif
