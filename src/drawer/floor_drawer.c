/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_drawer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 22:59:32 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/27 23:11:23 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./drawer_private.h"

void	floor_drawer(t_cub3d *cub3d)
{
	int	horizontal_height;
	int	color;
	int	win_x;
	int	win_y;

	horizontal_height = (int)floor(calc_horizontal_screen_height(&(cub3d->player)));
	color \
		= mlx_get_color_value(cub3d->mlx.mlx_ptr, cub3d->settings.floor_color);
	win_y = horizontal_height;
	while (win_y < W_HEIGHT)
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
