/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeannea <jjeannea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 11:22:31 by jjeannea          #+#    #+#             */
/*   Updated: 2026/07/15 15:56:02 by jjeannea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	if (argc != 2 || !has_cub_ext(argv[1]))
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

	if (!check_args(argc, argv))
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
	setup_hooks(&g);
	mlx_loop(g.mlx);
	return (0);
}
