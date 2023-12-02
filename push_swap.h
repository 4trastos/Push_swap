/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:34:28 by davgalle          #+#    #+#             */
/*   Updated: 2023/11/30 19:40:17 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H	
# define PUSH_SWAP_H

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack_node
{
	int					content;
	int					posittion;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

//*** startup algorithms ***

int		main(int argc, char *argv[]);

//*** create content nodes ***

char	**ft_split(const char *str, char c);
int		ft_atoi_dav(char *str, int *status);

//*** create nodes ***

t_stack_node	*ft_create_node(int content);
void	ft_stack_node(t_stack_node **a, t_stack_node *new);

//*** checker ***

int		ft_stacklen(t_stack_node *stack);
int		ft_check_arguments(char *s);
int		ft_repeat_content(t_stack_node **a, int content);
int		ft_checksort(t_stack_node *a);

//*** errros ***

void	**ft_free_string(char **str);
void	ft_cleanlist(t_stack_node **a);

//*** sort stack ***

int		ft_sort_stack(t_stack_node **a);

//*** movement swap ***






//*** movement push ***





//*** movement rotate ***






//*** movement reverse ***






#endif
