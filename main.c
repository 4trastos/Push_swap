/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:42:24 by davgalle          #+#    #+#             */
/*   Updated: 2023/11/28 19:34:22 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int	main(int argc, char *argv[])
{
	t_stack_node	*a;
	int				i;
	int				j;
	int				content;
	char			**str;

	a = NULL;
	i = 1;
	if (argc == 1)
		return (0);
	if (argc > 1)
	{
		while (i < argc)
		{
			str = ft_split(argv[i], ' ');
			j = 0;
			while (str[j] != NULL)
			{
				if (ft_check_arguments(str[j]))
				{
					ft_free_string(str);
					exit (1);
				}
				content = ft_atoi_dav(str[j]);
				ft_stack_node(&a, ft_create_node(content));
				ft_print_content(a);
				printf("%i\n", a->content);
				j++;
			}
			i++;
		}
	}
	return (0);
}
