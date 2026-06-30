/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeannea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 11:12:53 by jjeannea          #+#    #+#             */
/*   Updated: 2026/06/30 13:47:09 by jjeannea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	has_cub_ext(char *s)
{
	size_t	len;

	len = ft_strlen(s);
	if (len < 5)
		return (0);
	return (ft_strncmp(s + len - 4, ".cub", 4) == 0);
}

static int	check_args(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	if (!has_cub_ext(argv[1]))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	if (!check_args(argc, argv))
		return (ft_putstr_fd("Error\n", 2), 1);
	return (0);
}
