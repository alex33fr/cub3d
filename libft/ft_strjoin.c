/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:31:11 by aprivalo          #+#    #+#             */
/*   Updated: 2025/10/25 17:42:42 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tab_strjoin;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	i = 0;
	tab_strjoin = ft_calloc(len_s1 + len_s2 + 1, sizeof(char));
	if (!tab_strjoin)
		return (NULL);
	while (i < (len_s1 + len_s2))
	{
		if (i < len_s1)
			tab_strjoin[i] = s1[i];
		else
			tab_strjoin[i] = s2[i - len_s1];
		i++;
	}
	tab_strjoin[i] = '\0';
	return (tab_strjoin);
}
