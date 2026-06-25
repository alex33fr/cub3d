/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_len_un.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 01:06:44 by aprivalo          #+#    #+#             */
/*   Updated: 2025/12/25 01:27:09 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_int_len_un(unsigned int n)
{
	unsigned int	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}
