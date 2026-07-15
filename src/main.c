/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeannea <jjeannea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 11:22:31 by jjeannea          #+#    #+#             */
/*   Updated: 2026/07/15 14:58:16 by jjeannea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"

static int	has_cub_ext(char *s)
{
	size_t	len;
	int		cmp;

	len = ft_strlen(s);
	if (len < 5)
		return (0);
	cmp = ft_strncmp(s + len - 4, ".cub", 4);
	return (cmp == 0);
}

static int	check_args(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	if (!has_cub_ext(argv[1]))
		return (0);
	return (1);
}

static void	fail(t_game *g, int mlx_up)
{
	ft_putstr_fd("Error\n", 2);
	if (mlx_up)
		cleanup_mlx(g);
	free_game(g);
}

static	int load_colors(t_game *g, char *path)
{
	t_data data;

	ft_bzero(&data, sizeof(t_data));
	if (!ft_parsing(path, &data))
		return (1);
	g->floor = rgb_to_int(data.color_f[0], data.color_f[1], data.color_f[2]);
	printf("floor = %d, %d, %d\n", data.color_f[0], data.color_f[1], data.color_f[2]);
	g->ceiling = rgb_to_int(data.color_c[0], data.color_c[1], data.color_c[2]);
	printf("floor = %d, %d, %d\n", data.color_c[0], data.color_c[1], data.color_c[2]);

	return (0);
}


int	main(int argc, char **argv)
{
	t_game	g;

	if (!check_args(argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	ft_bzero(&g, sizeof(t_game));
	load_colors(&g, argv[1]);
	
	if (init_mlx(&g))
	{
		fail(&g, 1);
		return (1);
	}
	setup_hooks(&g);
	mlx_loop(g.mlx);
	return (0);
}
