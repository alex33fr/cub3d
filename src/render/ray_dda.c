/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_dda.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeannea <jjeannea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 11:22:31 by jjeannea          #+#    #+#             */
/*   Updated: 2026/07/15 15:56:02 by jjeannea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

void	run_dda(t_game *g, t_ray *r)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (r->side_dist_x < r->side_dist_y)
		{
			r->side_dist_x += r->delta_x;
			r->map_x += r->step_x;
			r->side = 0;
		}
		else
		{
			r->side_dist_y += r->delta_y;
			r->map_y += r->step_y;
			r->side = 1;
		}
		if (is_wall(g, r->map_x, r->map_y))
			hit = 1;
	}
}

void	set_wall(t_ray *r)
{
	if (r->side == 0)
		r->perp_dist = r->side_dist_x - r->delta_x;
	else
		r->perp_dist = r->side_dist_y - r->delta_y;
	if (r->perp_dist < EPS)
		r->perp_dist = EPS;
	r->line_h = (int)(WIN_H / r->perp_dist);
	if (r->line_h < 1)
		r->line_h = 1;
	r->draw_start = -r->line_h / 2 + WIN_H / 2;
	if (r->draw_start < 0)
		r->draw_start = 0;
	r->draw_end = (r->line_h - 1) / 2 + WIN_H / 2;
	if (r->draw_end >= WIN_H)
		r->draw_end = WIN_H - 1;
}
