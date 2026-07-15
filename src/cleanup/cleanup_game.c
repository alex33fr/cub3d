/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeannea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 14:51:36 by jjeannea          #+#    #+#             */
/*   Updated: 2026/06/30 19:08:41 by jjeannea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_map(t_game *g)
{
	int	i;

	if (!g->map)
		return ;
	i = 0;
	while (g->map[i])
	{
		free(g->map[i]);
		i++;
	}
	free(g->map);
	g->map = NULL;
}

void	free_game(t_game *g)
{
	int	i;

	free_map(g);
	i = 0;
	while (i < FACE_COUNT)
	{
		free(g->tex_path[i]);
		g->tex_path[i] = NULL;
		i++;
	}
}
