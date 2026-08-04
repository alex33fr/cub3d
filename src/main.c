/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 11:22:31 by jjeannea          #+#    #+#             */
/*   Updated: 2026/08/04 10:56:45 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_args(int argc)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (1);
}

static void	fail(t_game *g, int mlx_up)
{
	ft_putstr_fd("Error\n", 2);
	if (mlx_up)
		cleanup_mlx(g);
	free_game(g);
}

int	main(int argc, char **argv)
{
	t_game	g;

	if (!check_args(argc))
		return (1);
	ft_bzero(&g, sizeof(t_game));
	if (parse_scene(&g, argv[1]))
	{
		fail(&g, 0);
		return (1);
	}
	if (init_mlx(&g))
	{
		fail(&g, 1);
		return (1);
	}
	if (load_textures(&g))
	{
		fail(&g, 1);
		return (1);
	}
	setup_hooks(&g);
	mlx_loop(g.mlx);
	return (0);
}
