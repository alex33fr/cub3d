/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:06:13 by aprivalo          #+#    #+#             */
/*   Updated: 2025/10/26 17:09:40 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*tab_strmapi;
	unsigned int	i;
	unsigned int	t;

	if (!s || !f)
		return (NULL);
	t = ft_strlen(s);
	i = 0;
	tab_strmapi = ft_calloc(t + 1, sizeof(char));
	if (!tab_strmapi)
		return (NULL);
	while (s[i])
	{
		tab_strmapi[i] = f(i, s[i]);
		i++;
	}
	tab_strmapi[i] = '\0';
	return (tab_strmapi);
}
