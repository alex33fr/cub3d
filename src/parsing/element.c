/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 13:55:37 by aprivalo          #+#    #+#             */
/*   Updated: 2026/07/07 14:22:12 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	parse_rgb(char *s, int *dst)
{
	int	i;
	int	val;
	int	digits;

	i = 0;
	while (i < 3)
	{
		val = 0;
		digits = 0;
		while (ft_isdigit(*s))
		{
			val = val * 10 + (*s++ - '0');
			digits++;
		}
		if (digits == 0 || val > 255)
			return (1);
		dst[i] = val;
		if (i < 2 && *s++ != ',')
			return (1);
		i++;
	}
	if (*s != '\0')
		return (1);
	return (0);
}

static int	fill_texture(t_data *data, char **tok)
{
	char	**dst;

	if (tok[0][0] == 'N')
		dst = &data->tex_no;
	else if (tok[0][0] == 'S')
		dst = &data->tex_so;
	else if (tok[0][0] == 'W')
		dst = &data->tex_we;
	else
		dst = &data->tex_ea;
	if (*dst)
		return (1);
	*dst = ft_strdup(tok[1]);
	if (!*dst)
		return (1);
	return (0);
}

static int	fill_color(t_data *data, char **tok)
{
	int	ret;

	if (tok[0][0] == 'F')
	{
		if (data->color_f[0] != -1)
			return (1);
		ret = parse_rgb(tok[1], data->color_f);
	}
	else
	{
		if (data->color_c[0] != -1)
			return (1);
		ret = parse_rgb(tok[1], data->color_c);
	}
	return (ret);
}

static int	fill_element(t_data *data, char *line)
{
	char	**tok;
	int		ret;
	int		i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	line[i] = '\0';
	tok = ft_split(line, ' ');
	if (!tok)
		return (1);
	i = 0;
	while (tok[i])
		i++;
	if (i != 2)
	{
		ft_free_tab(tok);
		return (1);
	}
	if (tok[0][0] == 'F' || tok[0][0] == 'C')
		ret = fill_color(data, tok);
	else
		ret = fill_texture(data, tok);
	ft_free_tab(tok);
	return (ret);
}

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
	return (0);
}
