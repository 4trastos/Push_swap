/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:24:46 by davgalle          #+#    #+#             */
/*   Updated: 2024/01/03 15:55:42 by davgalle         ###   ########.fr       */
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
	int					position;
	int					content;
	int					speed;
	bool				near_center;
	bool				faster;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
	struct s_stack_node	*target_node;
}	t_stack_node;

//*** mathematics ***

void			ft_speed_groups(t_stack_node *a, t_stack_node *b);

//*** create content nodes ***

char			**ft_split(char *str, char c);
int				ft_atoi_dav(char *str, int *status);

//*** auxiliary functions ***

bool			checksort(t_stack_node *a);
int				ft_find_small(t_stack_node **stack);
t_stack_node	*ft_find_smaller(t_stack_node **stack);
t_stack_node	*ft_find_bigger(t_stack_node **stack);
t_stack_node	*ft_return_faster(t_stack_node *stack);
void			ft_target_node(t_stack_node *a, t_stack_node *b);
void			ft_speed_nodes(t_stack_node *a, t_stack_node *b);

//*** create nodes ***

t_stack_node	*ft_create_node(int content, int position);
void			ft_stack_node(t_stack_node **a, t_stack_node *new);

//*** checker ***

int				ft_checkarg(const char *s);
int				ft_checksort(t_stack_node *a);
int				ft_repeat_content(t_stack_node *a, int content);
int				ft_check_sort(t_stack_node *a);
void			ft_center_position(t_stack_node *stack);

//*** errros ***

void			ft_free_string(char **str);
void			ft_free_argv(char **argv);
void			ft_error(t_stack_node **a, char **argv, bool check_argc);
void			ft_free_stack(t_stack_node **a);

//*** sort stack ***

void			ft_long_sort(t_stack_node **a, t_stack_node **b);
void			ft_stackfour(t_stack_node **a, t_stack_node **b);
void			ft_stackthree(t_stack_node **a);
int				ft_stacklen(t_stack_node *a);
void			ft_stackfive(t_stack_node **a, t_stack_node **b);
void			ft_move_nodes(t_stack_node **a, t_stack_node **b);

//*** movement swap ***

void			ft_swap(t_stack_node **a);
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);

//*** movement push ***

void			ft_push(t_stack_node **dst, t_stack_node **src);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **a, t_stack_node **b);

//*** movement rotate ***

void			ft_rotate(t_stack_node **a);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);

//*** movement reverse ***

void			ft_reverse_rotate(t_stack_node **a);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			ft_rotate_both(t_stack_node **a, t_stack_node **b,
					t_stack_node *faster_node);
void			ft_reverse_rotate_both(t_stack_node **a, t_stack_node **b,
					t_stack_node *faster_node);
void			ft_finish_rotation(t_stack_node **stack, t_stack_node *top_node,
					char stack_name);

//*** BONUS ***

void			checker(t_stack_node *a);

#endif
