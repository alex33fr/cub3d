/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 11:15:08 by jjeannea          #+#    #+#             */
/*   Updated: 2026/07/15 19:36:09 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include "mlx.h"
# include "libft.h"
# include "parsing.h"

# define WIN_W 1280
# define WIN_H 720

# define EPS 0.0001
# define COLL 0.10

# define K_ESC 65307
# define EV_KEYPRESS 2
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
void	free_game(t_game *g);

void	my_pixel_put(t_img *img, int x, int y, int color);
int		init_mlx(t_game *g);
int		render_frame(t_game *g);
void	setup_hooks(t_game *g);
void	close_game(t_game *g);
void	cleanup_mlx(t_game *g);

int		parse_scene(t_game *g, char *path);

#endif
