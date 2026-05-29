/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 00:06:44 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/29 17:24:55 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./drawer_private.h"

void	drawer(t_cub3d *cub3d)
{
	clear_depth_buffer();
	compute_screen_horizontal_pixel(camera());
	floor_drawer(cub3d);
	sky_drawer(cub3d);
	wall_drawer();
	mlx_put_image_to_window(mlx_ptr(), win_ptr(), image(WINDOW_IMG)->ptr, 0, 0);
	clear_depth_buffer();
}
