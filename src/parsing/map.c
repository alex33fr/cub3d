/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 11:05:55 by aprivalo          #+#    #+#             */
/*   Updated: 2026/07/07 13:08:05 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	**ft_store_map(char *av)
{
	int		fd;
	char	*line;
	char	**map;

	fd = ft_open_file(av);
	if (fd < 0)
		return (NULL);
	map = NULL;
	line = get_next_line(fd);
	while (line)
	{
		map = ft_add_line(map, line);
		line = get_next_line(fd);
	}
	close(fd);
	return (map);
}

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
