/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 11:27:21 by aprivalo          #+#    #+#             */
/*   Updated: 2026/08/04 11:39:56 by aprivalo         ###   ########.fr       */
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
 * @brief Tells whether (y, x) is off the grid: an actual open boundary.
 * A space stops the player exactly like a wall (see is_wall in
 * map_guard.c), so it is not a leak on its own, only running off the
 * grid (or off the end of a shorter row) is.
 * @param copy Map copy, @param y Row, @param x Column.
 * @return 1 if the cell is off the grid, 0 otherwise.
 */
static int	is_open(char **copy, int y, int x)
{
	if (y < 0 || !copy[y] || x < 0 || (size_t)x >= ft_strlen(copy[y]))
		return (1);
	return (0);
}

/**
 * @brief Checks every floor cell (visited or not) is walled on all 4 sides.
 * @param copy Map copy (visited cells were marked 'F' by the flood fill).
 * @return 1 if a floor cell touches an open boundary, 0 if fully enclosed.
 */
static int	outside_map(char **copy)
{
	int	y;
	int	x;

	y = 0;
	while (copy[y])
	{
		x = 0;
		while (copy[y][x])
		{
			if (ft_strchr("0NSEWF", copy[y][x]) && (is_open(copy, y - 1, x)
					|| is_open(copy, y + 1, x) || is_open(copy, y, x - 1)
					|| is_open(copy, y, x + 1)))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
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
	if (outside_map(copy))
		leak = 1;
	ft_free_tab(copy);
	return (leak);
}
