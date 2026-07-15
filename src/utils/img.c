/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeannea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 08:15:37 by jjeannea          #+#    #+#             */
/*   Updated: 2026/06/30 20:03:51 by jjeannea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Ecrit un pixel dans le buffer image (jamais mlx_pixel_put en boucle).
** Le garde x/y est OBLIGATOIRE : addr est un char* brut, un offset hors
** image corromprait le tas. line_len (pas WIN_W*4) car la ligne peut etre
** padee. *(unsigned int*) suppose bpp == 32 (cas standard 42).
*/
void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}
