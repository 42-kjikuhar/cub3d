/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky_drawer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 22:59:34 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/29 02:37:21 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./drawer_private.h"

void	sky_drawer(t_cub3d *cub3d)
{
	int	horizon;
	int	color;
	int	win_x;
	int	win_y;

	horizon = (int)ceil(screen()->horizontal_pixel);
	color \
		= mlx_get_color_value(cub3d->mlx.mlx_ptr, cub3d->settings.ceiling_color);
	win_y = 0;
	while (win_y < horizon)
	{
		win_x = 0;
		while (win_x < W_WIDTH)
		{
			*get_pixel_addr(&(cub3d->mlx.win_img), win_x, win_y) = color;
			++win_x;
		}
		++win_y;
	}
}
