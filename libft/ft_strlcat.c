/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:36:39 by aprivalo          #+#    #+#             */
/*   Updated: 2025/10/27 07:39:36 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dest;
	size_t	len_src;

	i = 0;
	len_src = ft_strlen(src);
	if (!dst && size == 0)
		return (len_src);
	len_dest = ft_strlen(dst);
	if (size == 0)
		return (len_src);
	if (size < len_dest)
		return (size + len_src);
	while ((len_dest + i) < (size - 1) && src[i])
	{
		dst[len_dest + i] = src[i];
		i++;
	}
	dst[len_dest + i] = '\0';
	return (len_src + len_dest);
}
