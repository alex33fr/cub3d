/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:41:45 by aprivalo          #+#    #+#             */
/*   Updated: 2025/10/25 14:41:48 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	cc;
	char	*p;

	cc = (char)c;
	p = (char *)s;
	while (*p)
	{
		if (*p == cc)
			return (p);
		p++;
	}
	if (cc == '\0')
		return (p);
	return (NULL);
}
