/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 11:22:31 by jjeannea          #+#    #+#             */
/*   Updated: 2026/07/19 12:48:16 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_H
# define GRAPHIC_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"

# define WIN_W 1280
# define WIN_H 720

# define EPS 0.0001
# define COLL 0.10

# define MOVE_SPEED 0.05
# define ROT_SPEED 0.03
# define PLANE_LEN 0.66

# define K_ESC 65307
# define K_W 119
# define K_A 97
# define K_S 115
# define K_D 100
# define K_LEFT 65363
# define K_RIGHT 65361

# define EV_KEYPRESS 2
# define EV_KEYRELEASE 3
# define EV_DESTROY 17

typedef enum e_face
{
	FACE_NO,
	FACE_SO,
	FACE_WE,
	FACE_EA,
	FACE_COUNT
}	t_face;

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_tex
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		w;
	int		h;
}	t_tex;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_input
{
	int	w;
	int	s;
	int	a;
	int	d;
	int	rot_l;
	int	rot_r;
}	t_input;

typedef struct s_ray
{
	double	dir_x;
	double	dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_x;
	double	delta_y;
	double	perp_dist;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		side;
	int		line_h;
	int		draw_start;
	int		draw_end;
}	t_ray;

typedef struct s_texdraw
{
	t_face	face;
	double	wall_x;
	int		tex_x;
	double	tex_pos;
	double	tex_step;
}	t_texdraw;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		img;
	char		*tex_path[FACE_COUNT];
	t_tex		tex[FACE_COUNT];
	char		**map;
	int			map_w;
	int			map_h;
	int			floor;
	int			ceiling;
	t_player	player;
	t_input		input;
}	t_game;

int		rgb_to_int(int r, int g, int b);

void	my_pixel_put(t_img *img, int x, int y, int color);

int		is_wall(t_game *g, int x, int y);

int		init_mlx(t_game *g);

int		load_textures(t_game *g);

int		render_frame(t_game *g);

void	init_ray(t_game *g, t_ray *r, int x);
void	init_step(t_game *g, t_ray *r);

void	run_dda(t_game *g, t_ray *r);
void	set_wall(t_ray *r);

t_face	select_face(t_ray *r);
double	wall_x_value(t_game *g, t_ray *r);
int		tex_pixel(t_tex *t, int x, int y);

void	draw_textured_column(t_game *g, t_ray *r, int x);

void	apply_move(t_game *g);

void	apply_rotation(t_game *g);

int		key_press(int key, t_game *g);
int		key_release(int key, t_game *g);

void	setup_hooks(t_game *g);
void	close_game(t_game *g);
int		game_loop(t_game *g);

void	cleanup_mlx(t_game *g);
void	free_game(t_game *g);

int		parse_scene(t_game *g, char *path);

#endif
