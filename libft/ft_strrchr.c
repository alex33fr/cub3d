/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:36:58 by aprivalo          #+#    #+#             */
/*   Updated: 2025/10/25 14:37:01 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	cc;
	char	*p;
	char	*result;

	cc = (char)c;
	p = (char *)s;
	result = NULL;
	while (*p)
	{
		if (*p == cc)
			result = p;
		p++;
	}
	if (cc == '\0')
		return (p);
	return (result);
}
