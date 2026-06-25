/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:41:14 by aprivalo          #+#    #+#             */
/*   Updated: 2025/10/25 14:41:17 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*cs;
	unsigned char		cc;

	cs = (const unsigned char *)s;
	cc = (unsigned char)c;
	while (n--)
	{
		if (*cs == cc)
			return ((void *)cs);
		cs++;
	}
	return (NULL);
}
