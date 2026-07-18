/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeannea <jjeannea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 11:22:31 by jjeannea          #+#    #+#             */
/*   Updated: 2026/07/15 15:56:02 by jjeannea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	grid_width(char **map, int start, int lines)
{
	int	w;
	int	len;
	int	k;

	w = 0;
	k = 0;
	while (k < lines)
	{
		len = (int)ft_strlen(map[start + k]);
		if (len > w)
			w = len;
		k++;
	}
	return (w);
}

static char	*pad_row(const char *src, int w)
{
	char	*dst;
	int		i;

	dst = malloc(w + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (i < w && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	while (i < w)
	{
		dst[i] = ' ';
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int	bridge_copy_grid(t_game *g, t_data *d)
{
	int	w;
	int	k;

	w = grid_width(d->map.map, d->map.start, d->map.lines);
	g->map = ft_calloc(d->map.lines + 1, sizeof(char *));
	if (!g->map)
		return (1);
	k = 0;
	while (k < d->map.lines)
	{
		g->map[k] = pad_row(d->map.map[d->map.start + k], w);
		if (!g->map[k])
			return (1);
		k++;
	}
	g->map_w = w;
	g->map_h = d->map.lines;
	return (0);
}

int	parse_scene(t_game *g, char *path)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	if (ft_parsing(path, &data))
		return (1);
	if (bridge_copy_grid(g, &data))
	{
		ft_free_data(&data);
		return (1);
	}
	if (bridge_copy_meta(g, &data))
	{
		ft_free_data(&data);
		return (1);
	}
	ft_free_data(&data);
	return (0);
}
