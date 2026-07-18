/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeannea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 10:05:12 by jjeannea          #+#    #+#             */
/*   Updated: 2026/06/30 20:53:36 by jjeannea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	clear_background(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			if (y < WIN_H / 2)
				my_pixel_put(&g->img, x, y, g->ceiling);
			else
				my_pixel_put(&g->img, x, y, g->floor);
			x++;
		}
		y++;
	}
}

static void	cast_ray(t_game *g, int x)
{
	t_ray	r;

	init_ray(g, &r, x);
	init_step(g, &r);
	run_dda(g, &r);
	set_wall(&r);
	draw_textured_column(g, &r, x);
}

int	render_frame(t_game *g)
{
	int	x;

	clear_background(g);
	x = 0;
	while (x < WIN_W)
	{
		cast_ray(g, x);
		x++;
	}
	mlx_put_image_to_window(g->mlx, g->win, g->img.ptr, 0, 0);
	return (0);
}
