/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 11:22:31 by jjeannea          #+#    #+#             */
/*   Updated: 2026/07/19 07:56:48 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_dir(t_player *p, char c)
{
	p->dir_x = 0.0;
	p->dir_y = 0.0;
	if (c == 'N')
		p->dir_y = -1.0;
	else if (c == 'S')
		p->dir_y = 1.0;
	else if (c == 'E')
		p->dir_x = 1.0;
	else
		p->dir_x = -1.0;
}

static void	set_plane(t_player *p)
{
	p->plane_x = p->dir_y * PLANE_LEN;
	p->plane_y = -p->dir_x * PLANE_LEN;
}

static void	set_player(t_game *g, t_data *d)
{
	g->player.pos_x = d->map.spawn_x + 0.5;
	g->player.pos_y = (d->map.spawn_y - d->map.start) + 0.5;
	set_dir(&g->player, d->map.compass);
	set_plane(&g->player);
}

int	bridge_copy_meta(t_game *g, t_data *d)
{
	char	*srcs[FACE_COUNT];
	int		i;

	g->floor = rgb_to_int(d->color_f[0], d->color_f[1], d->color_f[2]);
	g->ceiling = rgb_to_int(d->color_c[0], d->color_c[1], d->color_c[2]);
	srcs[FACE_NO] = d->tex_no;
	srcs[FACE_SO] = d->tex_so;
	srcs[FACE_WE] = d->tex_we;
	srcs[FACE_EA] = d->tex_ea;
	i = 0;
	while (i < FACE_COUNT)
	{
		g->tex_path[i] = ft_strdup(srcs[i]);
		if (!g->tex_path[i])
			return (1);
		i++;
	}
	set_player(g, d);
	return (0);
}
