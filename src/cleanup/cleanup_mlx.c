/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeannea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 16:48:19 by jjeannea          #+#    #+#             */
/*   Updated: 2026/06/30 19:58:44 by jjeannea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cleanup_mlx(t_game *g)
{
	int	i;

	if (g->img.ptr)
		mlx_destroy_image(g->mlx, g->img.ptr);
	i = 0;
	while (i < FACE_COUNT)
	{
		if (g->tex[i].ptr)
			mlx_destroy_image(g->mlx, g->tex[i].ptr);
		i++;
	}
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	if (g->mlx)
	{
		mlx_do_key_autorepeaton(g->mlx);
		mlx_destroy_display(g->mlx);
		free(g->mlx);
	}
}
