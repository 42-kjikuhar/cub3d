/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling_drawer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 22:05:29 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/31 22:05:58 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./drawer_private.h"

void	ceiling_drawer(void)
{
	int	horizon;
	int	color;
	int	win_x;
	int	win_y;

	horizon = (int)ceil(get_screen()->horizontal_pixel);
	color \
		= mlx_get_color_value(get_mlx_ptr(), get_color(COLOR_CEILING));
	win_y = 0;
	while (win_y < horizon)
	{
		win_x = 0;
		while (win_x < W_WIDTH)
		{
			*get_pixel_addr(get_image(IMG_WINDOW), win_x, win_y) = color;
			++win_x;
		}
		++win_y;
	}
}
