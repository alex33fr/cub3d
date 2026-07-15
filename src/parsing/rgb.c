/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 17:20:00 by aprivalo          #+#    #+#             */
/*   Updated: 2026/07/07 17:20:00 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/**
 * @brief Parses one RGB component starting at *s, advancing *s past it.
 * @param s Pointer to the cursor (advanced past the digits read),
 * @param val Parsed value, written on success.
 * @return 0 if the component is valid, 1 otherwise.
 */
static int	parse_component(char **s, int *val)
{
	int	digits;

	*val = 0;
	digits = 0;
	while (ft_isdigit(**s))
	{
		if (digits >= 3)
			return (1);
		*val = *val * 10 + (*(*s)++ - '0');
		digits++;
	}
	if (digits == 0 || *val > 255)
		return (1);
	return (0);
}

/**
 * @brief Parses a "R,G,B" string into 3 integers, rejecting any space.
 * @param s "R,G,B" string, @param dst Array of 3 ints to fill.
 * @return 0 if the 3 values are valid, 1 otherwise.
 */
int	parse_rgb(char *s, int *dst)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (parse_component(&s, &dst[i]))
			return (1);
		if (i < 2 && *s++ != ',')
			return (1);
		i++;
	}
	if (*s != '\0')
		return (1);
	return (0);
}
