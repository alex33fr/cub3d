/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 22:35:03 by aprivalo          #+#    #+#             */
/*   Updated: 2026/07/07 13:49:26 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_open_file(char *av)
{
	int	fd;

	if (!av)
		return (-1);
	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (-1);
	return (fd);
}

void	ft_free_data(t_data *data)
{
	free(data->tex_no);
	free(data->tex_so);
	free(data->tex_we);
	free(data->tex_ea);
	ft_free_tab(data->map.map);
}