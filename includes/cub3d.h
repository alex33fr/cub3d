/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeannea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 11:15:08 by jjeannea          #+#    #+#             */
/*   Updated: 2026/06/30 20:12:47 by jjeannea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "graphic.h"
# include "parsing.h"

int	bridge_copy_grid(t_game *g, t_data *d);
int	bridge_copy_meta(t_game *g, t_data *d);

#endif
