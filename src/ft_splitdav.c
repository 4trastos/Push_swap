/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_dav.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:13:10 by davgalle          #+#    #+#             */
/*   Updated: 2023/12/18 20:10:45 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_words_complete(char *str, char c)
{
	static int	cursor = 0;
	char		*next_str;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (str[cursor] == c)
		++cursor;
	while ((str[cursor + len] != c) && str[cursor + len])
		++len;
	next_str = malloc((size_t)len * sizeof(char) + 1);
	if (! next_str)
		return (NULL);
	while ((str[cursor] != c) && str[cursor])
		next_str[i++] = str[cursor++];
	next_str[i] = '\0';
	return (next_str);
}

static int	ft_words(char *str, char c)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*str)
	{
		inside_word = false;
		while (*str == c && *str)
			++str;
		while (*str != c && *str)
		{
			if (!inside_word)
			{
				++count;
				inside_word = true;
			}
			++str;
		}
	}
	return (count);
}

char	**ft_split(char *str, char c)
{
	int		i;
	char	**new;
	int		words;

	words = ft_words(str, c);
	if (!words)
		exit(1);
	new = (char **)malloc(sizeof(char *) * (size_t)(words + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (words-- >= 0)
	{
		if (i == 0)
		{
			new[i] = malloc(sizeof(char));
			if (!new[i])
				return (NULL);
			new[i++][0] = '\0';
			continue ;
		}
		new[i++] = ft_words_complete(str, c);
	}
	new[i] = NULL;
	return (new);
}
