/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 17:43:48 by aprivalo          #+#    #+#             */
/*   Updated: 2025/10/27 07:41:39 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_charset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_start_s1(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i] && ft_charset(s1[i], set))
		i++;
	return (i);
}

int	ft_end_s1(char const *s1, char const *set, size_t start_len)
{
	size_t	i;

	i = ft_strlen(s1);
	while (i > start_len && ft_charset(s1[i - 1], set))
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tab_strtrim;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	start = ft_start_s1(s1, set);
	end = ft_end_s1(s1, set, start);
	i = 0;
	tab_strtrim = ft_calloc(end - start + 1, sizeof(char));
	if (!tab_strtrim)
		return (NULL);
	while (start < end)
	{
		tab_strtrim[i] = s1[start];
		i++;
		start++;
	}
	tab_strtrim[i] = '\0';
	return (tab_strtrim);
}
