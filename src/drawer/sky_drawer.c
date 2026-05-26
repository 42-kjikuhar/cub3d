/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky_drawer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 22:59:34 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/25 14:27:08 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./drawer_private.h"

void	sky_drawer(t_cub3d *cub3d)
{
	int const	horizontal_height \
		= (int)ceil(calc_horizontal_height(&(cub3d->player)));
	int	const	color \
		= mlx_get_color_value(cub3d->mlx.mlx_ptr, cub3d->settings.ceiling_color);
	int			win_x;
	int		 	win_y;

	win_x = 0;
	while (win_x < W_WIDTH)
	{
		win_y = 0;
		while (win_y <= horizontal_height)
		{
			*get_pixel_addr(&(cub3d->mlx.win_img), win_x, win_y) = color;
			++win_y;
		}
		++win_x;
	}
}
