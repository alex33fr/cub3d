/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 10:47:14 by aprivalo          #+#    #+#             */
/*   Updated: 2025/10/25 14:21:11 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tab_substr;
	size_t	i;
	size_t	s_len;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		tab_substr = ft_calloc(1, 1);
		return (tab_substr);
	}
	if (len > s_len - start)
		len = s_len - start;
	tab_substr = ft_calloc(len + 1, sizeof(char));
	if (!tab_substr)
		return (NULL);
	while (i < len && s[start + i])
	{
		tab_substr[i] = s[start + i];
		i++;
	}
	return (tab_substr);
}
