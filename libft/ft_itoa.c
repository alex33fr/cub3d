/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:58:20 by aprivalo          #+#    #+#             */
/*   Updated: 2025/12/25 01:24:38 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_init(long *nb, long *sign, char **tab_itoa)
{
	if (*nb == 0)
	{
		*tab_itoa = ft_calloc(2, sizeof(char));
		if (!*tab_itoa)
			return (-1);
		(*tab_itoa)[0] = '0';
		return (1);
	}
	if (*nb < 0)
	{
		*sign = 1;
		*nb *= -1;
	}
	return (0);
}

char	*ft_itoa(int n)
{
	char		*tab_itoa;
	long int	len;
	long int	nb;
	long int	sign;
	long int	state;

	nb = (long)n;
	sign = 0;
	state = ft_init(&nb, &sign, &tab_itoa);
	if (state == -1)
		return (NULL);
	if (state == 1)
		return (tab_itoa);
	len = ft_int_len(n) + sign;
	tab_itoa = ft_calloc(len + 1, sizeof(char));
	if (!tab_itoa)
		return (NULL);
	while (nb > 0)
	{
		tab_itoa[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	if (sign)
		tab_itoa[0] = '-';
	return (tab_itoa);
}
