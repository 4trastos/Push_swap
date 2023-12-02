/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:42:24 by davgalle          #+#    #+#             */
/*   Updated: 2023/12/02 19:41:24 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_stack_node *a)
{
    while (a != NULL)
    {
        printf("%d\n", a->content);
        a = a->next;
    }
}

void	ft_sort_stack(t_stack_node **a)
{
	t_stack_node	*b;

	b = NULL;
	if (!ft_checksort(*a))
	{
		if (ft_stacklen(*a) == 2)
		{
			printf("Hay 2 Nodos\n");
			sa(a);
		}
		if (ft_stacklen(*a) == 3)
		{
			printf("Tiene 3 nodos\n");
//			ft_pushswap(a);
			exit (1);
		}
		if (ft_stacklen(*a) > 3)
		{
			printf("Hay mas de 3 nodos\n");
//			ft_pushswap_long(a, &b);
			exit (1);
		}
	}
	else
	{
		printf("Están ordenados \n");
		exit (1);
	}
}

int	main(int argc, char *argv[])
{
	t_stack_node	*a;
	int				i;
	int				j;
	int				content;
	char			**str;
	int				status;

	a = NULL;
	status = 0;
	i = 1;
	if (argc <= 1)
		exit (1);
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
		printf("Contenido del stack después de la ordenación:\n");
        print_stack(a);
	}
	ft_freelist(&a);
}
