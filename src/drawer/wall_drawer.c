/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_drawer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 22:52:46 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/26 22:51:03 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./drawer_private.h"

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
