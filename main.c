/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:47:27 by davgalle          #+#    #+#             */
/*   Updated: 2023/12/15 22:45:25 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(const t_stack_node *a)
{
    const t_stack_node *aux;

	aux	= a;
    while (aux != NULL)
    {
        printf("%d\n", aux->content);
        aux = aux->next;
    }
}

void	ft_leaks(void)
{
	system("leaks -q push_swap");
}

void ft_init_groups(t_stack_node *a)
{
  if (a == NULL)
    return;

  if (a->content % 3 == 0)
    a->group = 3;
  else if (a->content % 6 == 0)
    a->group = 6;
  else
    a->group = 9;
  ft_init_groups(a->next);
}

void	ft_create_stack(t_stack_node **a, char **argv, bool check_argc)
{
	int	content;
	int	i;
	int	status;

	i = 0;
	status = 0;
	while (argv[i])
	{
		if (ft_checkarg(argv[i]))
			ft_error(a, argv, check_argc);
		content = ft_atoi_dav(argv[i], &status);
		if (status == 1)
			ft_error(a, argv, check_argc);
		ft_stack_node(a, ft_create_node(content, i));
		if (ft_repeat_content(*a, content))
			ft_error(a, argv, check_argc);
		i++;
	}
	if (check_argc)
		ft_free_argv(argv);
	ft_init_groups(*a);
}

int	main(int argc, char **argv)
{
	atexit(ft_leaks);
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc <= 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	ft_create_stack(&a, argv + 1, argc == 2);
	if (!ft_check_sort(a))
	{
		if (ft_stacklen(a) == 2)
			sa(&a);
		if (ft_stacklen(a) == 3)
			ft_stackthree(&a);
		if (ft_stacklen(a) == 4)
			ft_stackfour(&a, &b);
		else
			ft_long_sort(&a, &b);
	}
	print_stack(a);
	ft_free_stack(&a);
	return (0);
}
