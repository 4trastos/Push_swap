/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:48:27 by nicgonza          #+#    #+#             */
/*   Updated: 2024/01/02 12:18:40 by nicgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (content > INT_MAX || content < INT_MIN)
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
	if (argc == 1 || (argc == 2 && argv[1][0] == 0))
	{
		write (2, "Error\n", 6);
		return (1);
	}
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
	checker(a);
	ft_free_stack(&a);
	return (0);
}
