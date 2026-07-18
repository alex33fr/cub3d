/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 22:25:40 by aprivalo          #+#    #+#             */
/*   Updated: 2026/07/18 18:01:03 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/**
 * @brief Checks the path ends with ".cub" and has a non-empty name before it.
 * @param av File path.
 * @return 0 if the extension is valid, 1 otherwise.
 */
static int	check_ext(char *av)
{
	int	len;
	int	ext;

	len = ft_strlen(av);
	if (len <= 4)
		return (1);
	ext = ft_strncmp(av + len - 4, ".cub", 4);
	if (ext != 0)
		return (1);
	return (0);
}

/**
 * @brief Chains separation, element parsing and map validation.
 * @param data Structure holding the raw stored map.
 * @return 0 if everything is valid, 1 at the first error.
 */
static int	parse_content(t_data *data)
{
	int	sep;
	int	elem;
	int	valid;

	sep = ft_separator(data);
	elem = 0;
	valid = 0;
	if (sep == 0)
		elem = ft_parse_elements(data);
	if (sep == 0 && elem == 0)
		valid = ft_valid_map(data);
	if (sep != 0 || elem != 0 || valid != 0)
		return (1);
	return (0);
}

/**
 * @brief Validates the extension, stores the file, then parses its content.
 * @param av Path to the .cub file
 * @param data Structure to fill.
 * @return 0 if the whole parsing succeeds, 1 on error.
 */
int	ft_parsing(char *av, t_data *data)
{
	int	ext;
	int	ret;

	if (!av || !data)
		return (1);
	ext = check_ext(av);
	if (ext != 0)
		return (1);
	data->color_f[0] = -1;
	data->color_c[0] = -1;
	data->map.map = ft_store_map(av);
	if (!data->map.map)
		return (1);
	ret = parse_content(data);
	if (ret != 0)
	{
		ft_free_data(data);
		return (1);
	}
	return (0);
}
