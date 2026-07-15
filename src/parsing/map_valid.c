/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 14:51:09 by aprivalo          #+#    #+#             */
/*   Updated: 2026/07/07 14:52:00 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/**
 * @brief Validates a map line's characters and records any spawn found.
 * @param data Structure, @param y Row, @param spawn Spawn counter (updated).
 * @return 0 if the line is valid, 1 if a forbidden character is found.
 */
static int	valid_line(t_data *data, int y, int *spawn)
{
	int		x;
	char	c;

	x = 0;
	while (data->map.map[y][x] && data->map.map[y][x] != '\n')
	{
		c = data->map.map[y][x];
		if (!ft_strchr("01NSEW ", c))
			return (1);
		if (ft_strchr("NSEW", c))
		{
			(*spawn)++;
			data->map.spawn_x = x;
			data->map.spawn_y = y;
			data->map.compass = c;
		}
		x++;
	}
	data->map.map[y][x] = '\0';
	return (0);
}

/**
 * @brief Validates every map line, requires exactly one spawn, and closure.
 * @param data Structure holding the map (start/lines bounds).
 * @return 0 if the map is valid and closed, 1 otherwise.
 */
int	ft_valid_map(t_data *data)
{
	int	y;
	int	spawn;
	int	ret;

	spawn = 0;
	y = data->map.start;
	while (y < data->map.start + data->map.lines)
	{
		ret = valid_line(data, y, &spawn);
		if (ret != 0)
			return (1);
		y++;
	}
	if (spawn != 1)
		return (1);
	ret = ft_check_closed(data);
	return (ret);
}
