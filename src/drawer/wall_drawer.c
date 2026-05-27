/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_drawer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 22:52:46 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/27 12:02:59 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./drawer_private.h"

static void	draw_wall(t_mlx *mlx, int const win_x, t_wall *wall);

void	wall_drawer(t_cub3d *cub3d)
{
	int		win_x;
	t_ray	ray;
	t_hit	hit;
	t_wall	wall;

	win_x = 0;
	while (win_x < W_WIDTH)
	{
		ray = init_ray(&(cub3d->player), win_x);
		// while (true)
		// {
			hit = dda_algorithm(&(cub3d->map), &ray);
			// if (hit.hit_side == NO_HIT)
			// 	break ;
			wall = compute_wall(&(cub3d->mlx), &(cub3d->player), &ray, &hit);
			draw_wall(&(cub3d->mlx), win_x, &wall);
		// }
		++win_x;
	}
}

static void	draw_wall(t_mlx *mlx, int const win_x, t_wall *wall)
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
