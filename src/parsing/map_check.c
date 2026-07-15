/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 13:05:14 by aprivalo          #+#    #+#             */
/*   Updated: 2026/07/15 10:43:24 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/**
 * @brief Tells whether the line starts with a texture or color identifier.
 * @param line Line to test.
 * @return 1 if it is an element, 0 otherwise.
 */
static int	is_element(char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
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

/**
 * @brief Tells whether the line is "blank": made only of spaces, tabs or
 * newlines (or completely empty).
 * @param line Line to test.
 * @return 1 if the line is blank, 0 as soon as a real character appears.
 */
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

/**
 * @brief Finds the 1st line that is neither blank nor an element.
 * @param data Structure holding the array of lines.
 * @return The map start index, or -1 if there is no map.
 */
static int	find_map_start(t_data *data)
{
	int	i;
	int	blank;
	int	elem;

	i = 0;
	while (data->map.map[i])
	{
		blank = is_blank(data->map.map[i]);
		elem = is_element(data->map.map[i]);
		if (blank == 0 && elem == 0)
			return (i);
		i++;
	}
	return (-1);
}

/**
 * @brief Finds the end of the map: the 1st blank line after start.
 * @param data Structure holding the lines, @param start Start of the map.
 * @return The index of the 1st blank line after the map, or the end index.
 */
static int	find_map_end(t_data *data, int start)
{
	int	i;
	int	blank;

	i = start;
	while (data->map.map[i])
	{
		blank = is_blank(data->map.map[i]);
		if (blank == 1)
			return (i);
		i++;
	}
	return (i);
}

/**
 * @brief Locates the map (start/lines) and checks only blank lines follow it.
 * @param data Structure holding the lines; fills start and lines.
 * @return 0 if the structure is valid, 1 otherwise (no map, or content after).
 */
int	ft_separator(t_data *data)
{
	int	i;
	int	blank;

	i = find_map_start(data);
	if (i < 0)
		return (1);
	data->map.start = i;
	i = find_map_end(data, i);
	data->map.lines = i - data->map.start;
	while (data->map.map[i])
	{
		blank = is_blank(data->map.map[i]);
		if (blank == 0)
			return (1);
		i++;
	}
	return (0);
}
