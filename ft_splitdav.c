/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_dav.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:13:10 by davgalle          #+#    #+#             */
/*   Updated: 2023/12/09 19:25:33 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**ft_empty_split(void)
{
	char	**aux;

	aux = (char **)malloc(sizeof(char *));
	if (!aux)
		return (NULL);
	aux[0] = NULL;
	return (aux);
}

static char	**ft_free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static char	*ft_words_complete(const char *str, int number)
{
	int		i;
	char	*line;

	i = 0;
	line = (char *)malloc(number + 1);
	if (!line)
		return (NULL);
	while (i < number)
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static int	ft_words(char const *str, char c)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		if (str[i] == '\0')
			return (z);
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			z++;
		i++;
	}
	return (z);
}

char	**ft_split(const char *str, char c)
{
	int		i;
	int		z;
	int		len_words;
	char	**new;

	if (!str || *str == 0)
		return (ft_empty_split());
	new = (char **)malloc(sizeof(char *) * (ft_words(str, c) + 1));
	i = 0;
	z = 0;
	while (str[i] != '\0' && z < ft_words(str, c))
	{
		while (str[i] == c)
			i++;
		len_words = i;
		while (str[i] != c && str[i] != '\0')
			i++;
		new[z] = ft_words_complete(&str[len_words], i - len_words);
		if (new[z++] == NULL)
			return (ft_free_str(new));
	}
	new[z] = NULL;
	return (new);
}
