/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_face.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeannea <jjeannea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 11:22:31 by jjeannea          #+#    #+#             */
/*   Updated: 2026/07/15 15:56:02 by jjeannea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

t_face	select_face(t_ray *r)
{
	if (r->side == 1)
	{
		if (r->dir_y > 0)
			return (FACE_NO);
		return (FACE_SO);
	}
	if (r->dir_x > 0)
		return (FACE_WE);
	return (FACE_EA);
}

double	wall_x_value(t_game *g, t_ray *r)
{
	double	wall_x;

	if (r->side == 0)
		wall_x = g->player.pos_y + r->perp_dist * r->dir_y;
	else
		wall_x = g->player.pos_x + r->perp_dist * r->dir_x;
	wall_x -= floor(wall_x);
	return (wall_x);
}

int	tex_pixel(t_tex *t, int x, int y)
{
	char	*px;

	px = t->addr + (y * t->line_len + x * (t->bpp / 8));
	return (*(int *)px);
}
