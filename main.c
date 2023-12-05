/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:42:24 by davgalle          #+#    #+#             */
/*   Updated: 2023/12/05 20:00:41 by davgalle         ###   ########.fr       */
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

void	ft_sort_stack(t_stack_node **a)
{
	t_stack_node	*b;
	int				len;

	b = NULL;
	len = ft_stacklen(*a);
	if (!ft_checksort(*a))
	{
		if (len == 2)
			sa(a);
		if (len == 3)
			ft_pushswapthree(a);
		if (len ==  4)
			ft_pushswapfour(a, &b);
		if (len == 5)
			ft_pushswapfour(a, &b);
		if (len > 5)
			printf("Hay más de 5 argumentos \n");
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
