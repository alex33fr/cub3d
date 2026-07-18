/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeannea <jjeannea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 11:22:31 by jjeannea          #+#    #+#             */
/*   Updated: 2026/07/15 15:56:02 by jjeannea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

static void	rotate_vec(double *x, double *y, double cs, double sn)
{
	double	old_x;

	old_x = *x;
	*x = old_x * cs - *y * sn;
	*y = old_x * sn + *y * cs;
}

static void	rotate_player(t_game *g, double angle)
{
	t_player	*p;
	double		cs;
	double		sn;

	p = &g->player;
	cs = cos(angle);
	sn = sin(angle);
	rotate_vec(&p->dir_x, &p->dir_y, cs, sn);
	rotate_vec(&p->plane_x, &p->plane_y, cs, sn);
}

void	apply_rotation(t_game *g)
{
	if (g->input.rot_l)
		rotate_player(g, -ROT_SPEED);
	if (g->input.rot_r)
		rotate_player(g, ROT_SPEED);
}
