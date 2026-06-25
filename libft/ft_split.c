/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 18:16:19 by aprivalo          #+#    #+#             */
/*   Updated: 2025/10/26 17:49:18 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_word(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (j);
}

void	ft_free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static char	**ft_input_split(char **tab_split, char const *s, char c)
{
	size_t	i;
	size_t	t;
	size_t	start;

	i = 0;
	t = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		tab_split[t] = ft_substr(s, start, i - start);
		if (!tab_split[t])
		{
			ft_free_tab(tab_split);
			return (NULL);
		}
		t++;
	}
	tab_split[t] = NULL;
	return (tab_split);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	char	**tab_splited;
	size_t	nb_words;

	if (!s)
		return (NULL);
	nb_words = ft_count_word(s, c);
	tab = ft_calloc(nb_words + 1, sizeof(char *));
	if (!tab)
		return (NULL);
	tab_splited = ft_input_split(tab, s, c);
	return (tab_splited);
}
