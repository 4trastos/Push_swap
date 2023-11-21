/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:31:35 by davgalle          #+#    #+#             */
/*   Updated: 2023/11/21 13:35:36 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"

char	**ft_error(void)
{
	char	**aux;

	aux = malloc(1);
	if (!aux)
		return (NULL);
	aux[0] = NULL;
	return (aux);
}

char	*ft_strings(const char *str, int n)
{
	char	*new;
	int		i;

	i = 0;
	new = malloc(n +1);
	if (!new)
		return (NULL);
	while (str[i] && i < n)
	{
		new[i] = str[i];
		i++;
	}
	return (new);
}

char	**ft_free_aux(char **aux)
{
	int		i;

	i = 0;
	while (aux[i])
	{
		free(aux[i]);
		i++;
	}
	free(aux);
	return (NULL);
}

int	ft_words(const char *s, char c)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i] == '\0'))
			z++;
		i++;
	}
	return (z);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		z;
	int		len_word;
	char	**aux;

	if (!s || *s == '\0')
		return (ft_error());
	aux = (char **)malloc(sizeof(char *) * (ft_words(s, c) + 1));
	if (!aux)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && z < ft_words(s, c))
	{
		while (s[i] == c)
			i++;
		len_word = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		aux[z] = ft_strings(&s[len_word], i - len_word);
		if (aux[z++] == NULL)
			return (ft_free_aux(aux));
	}
	aux[z] = NULL;
	return (aux);
}
/*
int main(void)
{
    const char *s = "---francinette-no-es---de--fiar-";
    char **aux = ft_split(s, '-');
    
    if (aux)
    {
        int i = 0;
        while (aux[i] != NULL)
        {
            printf("%s\n", aux[i]);
            i++;
        }
        ft_free_aux(aux);
    }
    else
    {
        printf("Error al dividir la cadena.\n");
    }

    return 0;
}*/
