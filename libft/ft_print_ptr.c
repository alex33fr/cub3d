/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 21:22:00 by aprivalo          #+#    #+#             */
/*   Updated: 2026/02/19 12:35:35 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_hex_ptr(unsigned long addr)
{
	char	buffer[32];
	int		i;
	int		result;

	if (addr == 0)
		return (write(1, "0", 1));
	i = 0;
	while (addr)
	{
		buffer[i] = BASE_HEX[addr % 16];
		addr /= 16;
		i++;
	}
	result = i;
	while (i--)
		write(1, &buffer[i], 1);
	return (result);
}

int	ft_print_ptr(va_list args)
{
	unsigned long	addr;
	int				len;

	addr = (unsigned long)va_arg(args, void *);
	if (addr == 0)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	len = ft_hex_ptr((unsigned long)addr);
	return (len + 2);
}
