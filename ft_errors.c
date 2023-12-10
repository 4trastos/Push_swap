/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:29:24 by davgalle          #+#    #+#             */
/*   Updated: 2023/12/10 12:04:56 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_string(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	write(1, "Error", 5);
	write(1, "\n", 1);
	free(str);
}

void	ft_free_argv(char **argv)
{
	int	i;

	i = -1;
	if (argv == NULL || *argv == NULL)
		return ;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv - 1);
}

void	ft_error(t_stack_node **a, char **argv, bool check_argc)
{
	ft_free_stack(a);
	if (check_argc)
		ft_free_argv(argv);
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_free_stack(t_stack_node **a)
{
	t_stack_node	*aux;
	t_stack_node	*dupl;

	if (a == NULL)
		return ;
	dupl = *a;
	while (dupl)
	{
		aux = dupl->next;
		free(dupl);
		dupl = aux;
	}
	*a = NULL;
}
