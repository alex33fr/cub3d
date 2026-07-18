/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_load.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeannea <jjeannea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 11:22:31 by jjeannea          #+#    #+#             */
/*   Updated: 2026/07/15 15:56:02 by jjeannea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

static int	load_one(t_game *g, int i)
{
	t_tex	*t;

	t = &g->tex[i];
	t->ptr = mlx_xpm_file_to_image(g->mlx, g->tex_path[i], &t->w, &t->h);
	if (!t->ptr)
		return (1);
	t->addr = mlx_get_data_addr(t->ptr, &t->bpp, &t->line_len, &t->endian);
	if (!t->addr)
		return (1);
	return (0);
}

int	load_textures(t_game *g)
{
	int	i;

	i = 0;
	while (i < FACE_COUNT)
	{
		if (load_one(g, i))
			return (1);
		i++;
	}
	return (0);
}
