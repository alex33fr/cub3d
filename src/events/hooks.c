/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeannea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 09:40:55 by jjeannea          #+#    #+#             */
/*   Updated: 2026/06/30 20:41:18 by jjeannea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	close_game(t_game *g)
{
	cleanup_mlx(g);
	free_game(g);
	exit(0);
}

static int	on_destroy(t_game *g)
{
	close_game(g);
	return (0);
}

static int	on_keypress(int key, t_game *g)
{
	if (key == K_ESC)
		close_game(g);
	return (0);
}

void	setup_hooks(t_game *g)
{
	mlx_do_key_autorepeatoff(g->mlx);
	mlx_hook(g->win, EV_KEYPRESS, 1L << 0, on_keypress, g);
	mlx_hook(g->win, EV_DESTROY, 1L << 17, on_destroy, g);
	mlx_loop_hook(g->mlx, render_frame, g);
}
