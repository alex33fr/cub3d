/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 22:35:03 by aprivalo          #+#    #+#             */
/*   Updated: 2026/07/15 08:11:51 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/**
 * @brief Opens the file in read-only mode. 
 * @param av
 * @return The file descriptor (>= 0), or -1 if opening fails.
 */
int	ft_open_file(char *av)
{
	int	fd;

	if (!av)
		return (-1);
	fd = open(av, O_RDONLY | O_NONBLOCK);
	if (fd < 0)
		return (-1);
	return (fd);
}

/**
 * @brief Frees everything the parsing allocated
 * @param data
 */
void	ft_free_data(t_data *data)
{
	free(data->tex_no);
	free(data->tex_so);
	free(data->tex_we);
	free(data->tex_ea);
	ft_free_tab(data->map.map);
}
