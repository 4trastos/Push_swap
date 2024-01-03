/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:47:27 by davgalle          #+#    #+#             */
/*   Updated: 2024/01/03 16:52:59 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	ft_checkmain(int argc, char **argv)
{
	if (argc == 1)
		return (true);
	if (argc == 2 && argv[1][0] == 0)
	{
		write (2, "Error\n", 6);
		return (true);
	}
	else
		return (false);
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
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (ft_checkmain(argc, argv))
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
		if (ft_stacklen(a) > 3)
			ft_long_sort(&a, &b);
	}
	ft_free_stack(&a);
	return (0);
}
