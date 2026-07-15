/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_fill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 15:20:00 by aprivalo          #+#    #+#             */
/*   Updated: 2026/07/07 15:20:00 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/**
 * @brief Returns the texture field matching the identifier's 1st letter.
 * @param data Structure, @param c 1st letter of the identifier.
 * @return Pointer to the char * field to fill.
 */
static char	**tex_slot(t_data *data, char c)
{
	if (c == 'N')
		return (&data->tex_no);
	if (c == 'S')
		return (&data->tex_so);
	if (c == 'W')
		return (&data->tex_we);
	return (&data->tex_ea);
}

/**
 * @brief Stores a texture path after checking its format and duplicates.
 * @param data Structure to fill, @param line "XX path" line.
 * @return 0 if stored, 1 on invalid format, duplicate or allocation failure.
 */
int	fill_texture(t_data *data, char *line)
{
	char	**token;
	char	**dst;

	token = ft_split(line, ' ');
	if (!token)
		return (1);
	if (!token[0] || !token[1] || token[2])
	{
		ft_free_tab(token);
		return (1);
	}
	dst = tex_slot(data, token[0][0]);
	if (*dst)
	{
		ft_free_tab(token);
		return (1);
	}
	*dst = ft_strdup(token[1]);
	ft_free_tab(token);
	if (!*dst)
		return (1);
	return (0);
}

/**
 * @brief Stores a color: requires exactly one space after F/C (any other
 * space is invalid), refuses a duplicate, then parses the RGB.
 * @param data Structure to fill, @param line "F R,G,B" or "C R,G,B" line.
 * @return 0 if stored, 1 on space error, duplicate or invalid RGB.
 */
int	fill_color(t_data *data, char *line)
{
	int	ret;

	if (line[1] != ' ')
		return (1);
	if (line[0] == 'F')
	{
		if (data->color_f[0] != -1)
			return (1);
		ret = parse_rgb(line + 2, data->color_f);
	}
	else
	{
		if (data->color_c[0] != -1)
			return (1);
		ret = parse_rgb(line + 2, data->color_c);
	}
	return (ret);
}
