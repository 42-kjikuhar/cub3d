/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 22:22:25 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/26 22:54:20 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "drawer_private.h"

void	draw_wall(t_mlx *mlx, int const win_x, t_wall *wall)
{
	double	texture_v;
	double	step;
	int		win_y;

	step = (double)wall->texture->height / wall->height;
	texture_v = (wall->draw_start - wall->top) * step;
	win_y = wall->draw_start;
	while (win_y <= wall->draw_end)
	{
		wall->texture_pixel.y = (int)texture_v;
		if (wall->texture_pixel.y == wall->texture->height)
			wall->texture_pixel.y--;
		*get_pixel_addr(&(mlx->win_img), win_x, win_y) \
			= *get_pixel_addr(\
				wall->texture, wall->texture_pixel.x, wall->texture_pixel.y);
		texture_v += step;
		++win_y;
	}
}
