/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeannea <jjeannea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 11:22:31 by jjeannea          #+#    #+#             */
/*   Updated: 2026/07/15 15:56:02 by jjeannea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

void	init_ray(t_game *g, t_ray *r, int x)
{
	double	camera_x;

	camera_x = 2.0 * (double)x / (double)WIN_W - 1.0;
	r->dir_x = g->player.dir_x + g->player.plane_x * camera_x;
	r->dir_y = g->player.dir_y + g->player.plane_y * camera_x;
	r->map_x = (int)g->player.pos_x;
	r->map_y = (int)g->player.pos_y;
	if (r->dir_x == 0)
		r->delta_x = 1e30;
	else
		r->delta_x = fabs(1.0 / r->dir_x);
	if (r->dir_y == 0)
		r->delta_y = 1e30;
	else
		r->delta_y = fabs(1.0 / r->dir_y);
}

void	init_step(t_game *g, t_ray *r)
{
	if (r->dir_x < 0)
	{
		r->step_x = -1;
		r->side_dist_x = (g->player.pos_x - r->map_x) * r->delta_x;
	}
	else
	{
		r->step_x = 1;
		r->side_dist_x = (r->map_x + 1.0 - g->player.pos_x) * r->delta_x;
	}
	if (r->dir_y < 0)
	{
		r->step_y = -1;
		r->side_dist_y = (g->player.pos_y - r->map_y) * r->delta_y;
	}
	else
	{
		r->step_y = 1;
		r->side_dist_y = (r->map_y + 1.0 - g->player.pos_y) * r->delta_y;
	}
}
