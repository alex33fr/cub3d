/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 11:05:55 by aprivalo          #+#    #+#             */
/*   Updated: 2026/07/15 07:22:33 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/**
 * @brief Open file and stores ALL its lines into a char **.
 * @param av Path to the .cub file.
 * @return The array of lines (NULL-terminated), or NULL on error.
 */
char	**ft_store_map(char *av)
{
	int		fd;
	char	*line;
	char	**map;
	char	**tmp;

	fd = ft_open_file(av);
	if (fd < 0)
		return (NULL);
	map = NULL;
	line = get_next_line(fd);
	while (line)
	{
		tmp = ft_add_line(map, line);
		if (!tmp)
		{
			free(line);
			ft_free_tab(map);
			close(fd);
			return (NULL);
		}
		map = tmp;
		line = get_next_line(fd);
	}
	close(fd);
	return (map);
}

/**
 * @brief Grows the line array by 1, appending line and NULL-terminating it.
 * @param map Old array (NULL on 1st call), @param line Line to append.
 * @return The new array, or NULL if allocation fails.
 */
char	**ft_add_line(char **map, char *line)
{
	char	**new;
	int		column;
	int		i;

	column = 0;
	while (map && map[column])
		column++;
	new = malloc(sizeof(char *) * (column + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (i < column)
	{
		new[i] = map[i];
		i++;
	}
	new[column] = line;
	new[column + 1] = NULL;
	free(map);
	return (new);
}
