/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 11:22:31 by jjeannea          #+#    #+#             */
/*   Updated: 2026/07/18 18:00:00 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	fail(t_game *g, int mlx_up)
{
	ft_putstr_fd("Error\n", 2);
	if (mlx_up)
		cleanup_mlx(g);
	free_game(g);
}

int	main(int argc, char **argv)
{
	int status;
	t_game	g;
	t_data	data;

	if (argc != 2)
	{
		ft_putstr_fd("Error 1\n", 2);
		return (1);
	}
	ft_bzero(&data, sizeof(t_data));
	ft_bzero(&g, sizeof(t_game));
	status = ft_parsing(argv[1], &data);
	if(status == 1)
	{
		ft_putstr_fd("Error 2\n", 2);
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
