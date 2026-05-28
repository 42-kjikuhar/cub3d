/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 00:06:44 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/27 22:54:06 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./drawer_private.h"

void	drawer(t_cub3d *cub3d)
{
	clear_depth_buffer();
	floor_drawer(cub3d);
	sky_drawer(cub3d);
	wall_drawer(cub3d);
	mlx_put_image_to_window(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr, \
										cub3d->mlx.win_img.img_ptr, 0, 0);
	clear_depth_buffer();
}
