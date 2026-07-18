/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 09:40:55 by jjeannea          #+#    #+#             */
/*   Updated: 2026/07/15 15:26:41 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

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

int	game_loop(t_game *g)
{
	apply_move(g);
	apply_rotation(g);
	render_frame(g);
	return (0);
}

void	setup_hooks(t_game *g)
{
	mlx_do_key_autorepeatoff(g->mlx);
	mlx_hook(g->win, EV_KEYPRESS, 1L << 0, key_press, g);
	mlx_hook(g->win, EV_KEYRELEASE, 1L << 1, key_release, g);
	mlx_hook(g->win, EV_DESTROY, 1L << 17, on_destroy, g);
	mlx_loop_hook(g->mlx, game_loop, g);
}
