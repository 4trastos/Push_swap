/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:42:24 by davgalle          #+#    #+#             */
/*   Updated: 2023/11/27 19:39:04 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int				i;
	int				j;
	int				content;
	char			**str;

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
				if (!ft_check_arguments(str[j]))
				{
					ft_free_string(str);
					exit (1);
				}
				content = ft_atoi(str[j]);
				ft_create_node(content);
//				else
//					printf("String Ok: %s\n", str[j]);
				j++;
			}
			i++;
		}
	}
	return (0);
}
