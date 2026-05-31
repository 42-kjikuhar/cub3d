/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 00:06:44 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/31 22:05:24 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./drawer_private.h"

void	drawer(void)
{
	clear_depth_buffer();
	compute_screen_horizontal_pixel(get_camera());
	floor_drawer();
	ceiling_drawer();
	wall_drawer();
	mlx_put_image_to_window(get_mlx_ptr(), get_win_ptr(), get_image(IMG_WINDOW)->ptr, 0, 0);
	clear_depth_buffer();
}
