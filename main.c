/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:42:24 by davgalle          #+#    #+#             */
/*   Updated: 2023/11/30 20:20:49 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort_stack(t_stack_node **a)
{
	if (ft_checksort(*a))
	{
		printf("Están ordenados y son más de uno \n");
		exit (1);
	}
	else
		printf("NO estan ordenasdos \n");
		return (1);
}

int	main(int argc, char *argv[])
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				i;
	int				j;
	int				content;
	char			**str;
	int				status;

	a = NULL;
	b = NULL;
	status = 0;
	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			str = ft_split(argv[i], ' ');
			j = 0;
			while (str[j] != NULL)
			{
				if (ft_check_arguments(str[j]))
					ft_free_string(str);
				content = ft_atoi_dav(str[j], &status);
				if (status == 1)
					ft_free_string(str);
				ft_stack_node(&a, ft_create_node(content));
				j++;
			}
			i++;
		}
		ft_sort_stack(&a);
	}
	return (0);
}
