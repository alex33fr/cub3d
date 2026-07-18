/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeannea <jjeannea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 11:22:31 by jjeannea          #+#    #+#             */
/*   Updated: 2026/07/15 15:56:02 by jjeannea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

static void	compute_tex_x(t_texdraw *d, t_ray *r, int tex_w)
{
	d->tex_x = (int)(d->wall_x * tex_w);
	if (r->side == 0 && r->dir_x > 0)
		d->tex_x = tex_w - d->tex_x - 1;
	if (r->side == 1 && r->dir_y < 0)
		d->tex_x = tex_w - d->tex_x - 1;
}

static void	init_texdraw(t_game *g, t_ray *r, t_texdraw *d)
{
	t_tex	*tex;

	d->face = select_face(r);
	tex = &g->tex[d->face];
	d->wall_x = wall_x_value(g, r);
	compute_tex_x(d, r, tex->w);
	d->tex_step = (double)tex->h / r->line_h;
	d->tex_pos = (r->draw_start - WIN_H / 2 + r->line_h / 2) * d->tex_step;
}

void	draw_textured_column(t_game *g, t_ray *r, int x)
{
	t_texdraw	d;
	t_tex		*tex;
	int			y;
	int			tex_y;

	init_texdraw(g, r, &d);
	tex = &g->tex[d.face];
	y = r->draw_start;
	while (y <= r->draw_end)
	{
		tex_y = (int)d.tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		else if (tex_y >= tex->h)
			tex_y = tex->h - 1;
		my_pixel_put(&g->img, x, y, tex_pixel(tex, d.tex_x, tex_y));
		d.tex_pos += d.tex_step;
		y++;
	}
}
