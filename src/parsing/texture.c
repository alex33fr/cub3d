/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 16:00:00 by aprivalo          #+#    #+#             */
/*   Updated: 2026/07/07 16:00:00 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/**
 * @brief Checks a texture path has a ".xpm" extension and is readable.
 * @param path Texture path.
 * @return 0 if the texture is valid, 1 otherwise.
 */
static int	check_xpm(char *path)
{
	int		fd;
	int		len;
	int		n;
	int		ext;
	char	buf;

	len = ft_strlen(path);
	if (len < 5)
		return (1);
	ext = ft_strncmp(path + len - 4, ".xpm", 4);
	if (ext != 0)
		return (1);
	fd = open(path, O_RDONLY | O_NONBLOCK);
	if (fd < 0)
		return (1);
	n = read(fd, &buf, 1);
	close(fd);
	if (n < 0)
		return (1);
	return (0);
}

/**
 * @brief Validates the 4 texture paths (NO/SO/WE/EA) via check_xpm.
 * @param data Structure holding the texture paths.
 * @return 0 if all 4 are valid, 1 as soon as one texture is invalid.
 */
int	check_textures(t_data *data)
{
	int	ret;

	ret = check_xpm(data->tex_no);
	if (ret != 0)
		return (1);
	ret = check_xpm(data->tex_so);
	if (ret != 0)
		return (1);
	ret = check_xpm(data->tex_we);
	if (ret != 0)
		return (1);
	ret = check_xpm(data->tex_ea);
	if (ret != 0)
		return (1);
	return (0);
}
