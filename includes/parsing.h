/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 09:00:00 by aprivalo          #+#    #+#             */
/*   Updated: 2026/07/15 20:30:49 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "libft.h"

typedef struct s_map
{
	char	**map;
	int		start;
	int		lines;
	int		spawn_x;
	int		spawn_y;
	char	compass;
}	t_map;

typedef struct s_data
{
	int		color_f[3];
	int		color_c[3];
	char	*tex_no;
	char	*tex_so;
	char	*tex_we;
	char	*tex_ea;
	t_map	map;
}	t_data;

typedef struct s_cell
{
	int	y;
	int	x;
}	t_cell;

typedef struct s_stack
{
	t_cell	*data;
	int		top;
}	t_stack;

int		ft_separator(t_data *data);
int		is_blank(char *line);
int		fill_texture(t_data *data, char *line);
int		fill_color(t_data *data, char *line);
int		parse_rgb(char *s, int *dst);
int		check_textures(t_data *data);
int		ft_parse_elements(t_data *data);
int		ft_valid_map(t_data *data);
int		ft_check_closed(t_data *data);
int		ft_flood_fill(char **map, int y, int x);
int		ft_parsing(char *av, t_data *data);
int		ft_open_file(char *av);
void	ft_free_data(t_data *data);
char	**ft_store_map(char *av);
char	**ft_add_line(char **map, char *line);

#endif