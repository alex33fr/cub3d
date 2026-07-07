/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 13:05:14 by aprivalo          #+#    #+#             */
/*   Updated: 2026/07/07 13:08:19 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	is_element(char *line)
{
	if (!ft_strncmp(line, "NO ", 3))
		return (1);
	if (!ft_strncmp(line, "SO ", 3))
		return (1);
	if (!ft_strncmp(line, "WE ", 3))
		return (1);
	if (!ft_strncmp(line, "EA ", 3))
		return (1);
	if (!ft_strncmp(line, "F ", 2))
		return (1);
	if (!ft_strncmp(line, "C ", 2))
		return (1);
	return (0);
}

int	is_blank(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_strchr(" \t\n", line[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_separator(t_data *data)
{
	int	i;

	i = 0;
	while (data->map.map[i]
		&& (is_blank(data->map.map[i]) || is_element(data->map.map[i])))
		i++;
	if (!data->map.map[i])
		return (1);
	data->map.start = i;
	while (data->map.map[i])
	{
		if (is_blank(data->map.map[i]) || is_element(data->map.map[i]))
			return (1);
		i++;
	}
	data->map.lines = i - data->map.start;
	return (0);
}

int	ft_valid_map(t_data *data)
{
	(void)data;
	return (0);
}