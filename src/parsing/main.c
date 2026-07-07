/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 11:39:48 by aprivalo          #+#    #+#             */
/*   Updated: 2026/07/07 14:30:42 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "libft.h"

int	main(int ac, char **av)
{
	int		status;
	t_data	data;
	
	if (ac != 2)
	{
		ft_putstr_fd("Error 1: ./cub3D maps/*.cub\n", 2);
		return (1);
	}
	status = 0;
	ft_bzero(&data, sizeof(data));
	status = ft_parsing(av[1], &data);
	if (status == 1)
	{
		ft_putstr_fd("Error 2: bad args or cannot open map\n", 2);
		return (status);
	}
	ft_free_data(&data);
	return (0);
}
