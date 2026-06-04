/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_drawer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 22:59:32 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/04 18:07:31 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./drawer_private.h"

void	floor_drawer(void)
{
	int	horizon;
	int	color;
	int	win_x;
	int	win_y;

	horizon = (int)floor(get_screen()->horizontal_pixel);
	if (horizon < 0)
		horizon = 0;
	color = mlx_get_color_value(get_mlx_ptr(), get_color(COLOR_FLOOR));
	win_y = horizon;
	while (win_y < W_HEIGHT)
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
