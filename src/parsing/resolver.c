/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 11:27:21 by aprivalo          #+#    #+#             */
/*   Updated: 2026/07/07 11:27:55 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/**
 * @brief Appends dup to copy, freeing both on allocation failure.
 * @param copy Current array, @param dup Line to append.
 * @return The grown array, or NULL on failure (copy and dup already freed).
 */
static char	**add_or_fail(char **copy, char *dup)
{
	char	**tmp;

	tmp = ft_add_line(copy, dup);
	if (!tmp)
	{
		free(dup);
		ft_free_tab(copy);
		return (NULL);
	}
	return (tmp);
}

/**
 * @brief Duplicates the map lines so the original isn't altered by the flood.
 * @param data Structure holding the map and its bounds (start, lines).
 * @return The copy (char **) NULL-terminated, or NULL on failure.
 */
static char	**copy_map(t_data *data)
{
	char	**copy;
	char	*dup;
	int		i;

	copy = NULL;
	i = 0;
	while (i < data->map.lines)
	{
		dup = ft_strdup(data->map.map[data->map.start + i]);
		if (!dup)
		{
			ft_free_tab(copy);
			return (NULL);
		}
		copy = add_or_fail(copy, dup);
		if (!copy)
			return (NULL);
		i++;
	}
	return (copy);
}

/**
 * @brief Checks the map is closed by flood-filling a copy from the spawn.
 * @param data Structure holding the map and the spawn position.
 * @return 0 if the map is closed, 1 on leak or allocation failure.
 */
int	ft_check_closed(t_data *data)
{
	char	**copy;
	int		leak;
	int		y;
	int		x;

	copy = copy_map(data);
	if (!copy)
		return (1);
	y = data->map.spawn_y - data->map.start;
	x = data->map.spawn_x;
	leak = ft_flood_fill(copy, y, x);
	ft_free_tab(copy);
	return (leak);
}
