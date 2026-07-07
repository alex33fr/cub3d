/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 22:25:40 by aprivalo          #+#    #+#             */
/*   Updated: 2026/07/07 10:07:45 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_parsing(char *av, t_data **data)
{
	int len;
	int check_ext;

	if (!av || !data)
		return (1);
	len = ft_strlen(av);
	if (len <= 4)
		return (1);
	check_ext = ft_strncmp(av + len - 4, ".cub", 4);
	if (check_ext != 0)
		return (1);
	ft_printf("OK");
	return (0);
}
