/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_unit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:02:24 by davgalle          #+#    #+#             */
/*   Updated: 2023/12/09 11:59:02 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strlen(char *str)
{
	if (!str)
		return (0);
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}


char	*ft_customjoin(char *str, char *argv)
{
	char	*new;
	int		i;
	int		j;

	if (ft_strlen(argv) == 0)
		return (str);
	new = (char *)malloc(ft_strlen(str) + ft_strlen(argv) + 2);
	if (!new)
		return (NULL);
	j = 0;
	while (str[j] != '\0')
	{
		new[j] = str[j];
		j++;
	}
	i = 0;
	while (argv[i] != '\0')
	{
		new[j] = argv[i];
		i++;
		j++;
	}
	free(str);
	new[j] = ' ';
	new[j + 1] = '\0';
	return (new);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
