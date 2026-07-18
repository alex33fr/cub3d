/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeannea <jjeannea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 11:22:31 by jjeannea          #+#    #+#             */
/*   Updated: 2026/07/15 15:56:02 by jjeannea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

static void	set_key(t_input *in, int key, int val)
{
	if (key == K_W)
		in->w = val;
	else if (key == K_S)
		in->s = val;
	else if (key == K_A)
		in->a = val;
	else if (key == K_D)
		in->d = val;
	else if (key == K_LEFT)
		in->rot_l = val;
	else if (key == K_RIGHT)
		in->rot_r = val;
}

int	key_press(int key, t_game *g)
{
	if (key == K_ESC)
		close_game(g);
	set_key(&g->input, key, 1);
	return (0);
}

int	key_release(int key, t_game *g)
{
	set_key(&g->input, key, 0);
	return (0);
}
