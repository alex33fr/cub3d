/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeannea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 16:30:02 by jjeannea          #+#    #+#             */
/*   Updated: 2026/06/30 19:47:29 by jjeannea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_mlx(t_game *g)
{
	g->mlx = mlx_init();
	if (!g->mlx)
		return (1);
	g->win = mlx_new_window(g->mlx, WIN_W, WIN_H, "cub3D");
	if (!g->win)
		return (1);
	g->img.ptr = mlx_new_image(g->mlx, WIN_W, WIN_H);
	if (!g->img.ptr)
		return (1);
	g->img.addr = mlx_get_data_addr(g->img.ptr, &g->img.bpp,
			&g->img.line_len, &g->img.endian);
	if (!g->img.addr)
		return (1);
	return (0);
}
