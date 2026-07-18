/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeannea <jjeannea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 11:22:31 by jjeannea          #+#    #+#             */
/*   Updated: 2026/07/15 15:56:02 by jjeannea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

static void	move_axis_x(t_game *g, double dx)
{
	t_player	*p;
	double		margin;

	if (dx == 0.0)
		return ;
	p = &g->player;
	margin = COLL;
	if (dx < 0)
		margin = -COLL;
	if (!is_wall(g, (int)(p->pos_x + dx + margin), (int)p->pos_y))
		p->pos_x += dx;
}

static void	move_axis_y(t_game *g, double dy)
{
	t_player	*p;
	double		margin;

	if (dy == 0.0)
		return ;
	p = &g->player;
	margin = COLL;
	if (dy < 0)
		margin = -COLL;
	if (!is_wall(g, (int)p->pos_x, (int)(p->pos_y + dy + margin)))
		p->pos_y += dy;
}

void	apply_move(t_game *g)
{
	t_player	*p;
	double		dx;
	double		dy;

	p = &g->player;
	dx = (g->input.w - g->input.s) * p->dir_x * MOVE_SPEED;
	dy = (g->input.w - g->input.s) * p->dir_y * MOVE_SPEED;
	dx += (g->input.d - g->input.a) * p->plane_x * MOVE_SPEED;
	dy += (g->input.d - g->input.a) * p->plane_y * MOVE_SPEED;
	move_axis_x(g, dx);
	move_axis_y(g, dy);
}
