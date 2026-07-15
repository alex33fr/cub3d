/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 13:55:37 by aprivalo          #+#    #+#             */
/*   Updated: 2026/07/07 14:43:11 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/**
 * @brief Handles one element line, dispatching on its 1st letter.
 * @param data Structure to fill, @param line Element line.
 * @return 0 if the element is valid and stored, 1 otherwise.
 */
static int	fill_element(t_data *data, char *line)
{
	char	*nl;
	int		ret;

	nl = ft_strchr(line, '\n');
	if (nl)
		*nl = '\0';
	while (*line == ' ' || *line == '\t')
		line++;
	if (line[0] == 'F' || line[0] == 'C')
		ret = fill_color(data, line);
	else
		ret = fill_texture(data, line);
	return (ret);
}

/**
 * @brief Fills every element line, then checks all 6 are present and valid.
 * @param data Structure to fill.
 * @return 0 if all elements are valid, 1 otherwise.
 */
int	ft_parse_elements(t_data *data)
{
	int	i;
	int	blank;
	int	ret;

	i = 0;
	while (i < data->map.start)
	{
		blank = is_blank(data->map.map[i]);
		if (blank == 0)
		{
			ret = fill_element(data, data->map.map[i]);
			if (ret != 0)
				return (1);
		}
		i++;
	}
	if (!data->tex_no || !data->tex_so || !data->tex_we || !data->tex_ea)
		return (1);
	if (data->color_f[0] == -1 || data->color_c[0] == -1)
		return (1);
	ret = check_textures(data);
	return (ret);
}
