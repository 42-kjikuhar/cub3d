/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_drawer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 22:52:46 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/29 02:38:34 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./drawer_private.h"

static void	draw_wall_side_face(t_mlx *mlx, int const win_x, t_wall_side_face *side);
static void	draw_wall_top_face(t_mlx *mlx, int const win_x, t_wall_top_face *top);

void	wall_drawer(t_cub3d *cub3d)
{
	int		win_x;
	t_dda	dda;
	t_hit	hit;
	t_wall	wall;

	win_x = 0;
	while (win_x < W_WIDTH)
	{
		dda = init_dda_info(win_x);
		while (true)
		{
			hit = search_hitting_wall(&dda);
			if (hit.hit_side == NO_HIT)
				break ;
			wall = compute_wall(&(cub3d->mlx), &hit);
			draw_wall_side_face(&(cub3d->mlx), win_x, &(wall.side));
			draw_wall_top_face(&(cub3d->mlx), win_x, &(wall.top));
		}
		++win_x;
	}
}

// depthの線形補間は未実装
static void	draw_wall_side_face(t_mlx *mlx, int const win_x, t_wall_side_face *side)
{
	double	texture_v;
	double	texture_step;
	int		win_y;

	texture_step = (double)side->texture->height / side->size;
	texture_v = (side->draw_start - side->top) * texture_step;
	win_y = side->draw_start;
	while (win_y <= side->draw_end)
	{
		side->texture_pixel.y = (int)texture_v;
		if (side->texture_pixel.y == side->texture->height)
			side->texture_pixel.y -= 1;
		if (try_depth_buffer(side->top_depth, win_x, win_y))
		{
			*get_pixel_addr(&(mlx->win_img), win_x, win_y) \
				= *get_pixel_addr(side->texture, side->texture_pixel.x, side->texture_pixel.y);
		}
		texture_v += texture_step;
		++win_y;
	}
}

// depthの線形補間は未実装
static void	draw_wall_top_face(t_mlx *mlx, int const win_x, t_wall_top_face *top)
{
	int	color;
	int	win_y;

	color = mlx_get_color_value(mlx->mlx_ptr, top->color);
	win_y = top->draw_start;
	while (win_y <= top->draw_end)
	{
		if (try_depth_buffer(top->back_depth, win_x, win_y))
		{
			*get_pixel_addr(&(mlx->win_img), win_x, win_y) = color;
		}
		++win_y;
	}
}
