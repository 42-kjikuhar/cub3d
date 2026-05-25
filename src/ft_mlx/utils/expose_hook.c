/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 17:32:12 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/25 11:28:06 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	expose_hook(void *param)
{
	t_cub3d	*cub3d;

	cub3d = (t_cub3d *)param;
	// (void)cub3d;
	floor_drawer(cub3d);
	sky_drawer(cub3d);
	mlx_put_image_to_window(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr, cub3d->mlx.win_img.img_ptr, 0, 0);
	mlx_put_image_to_window(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr, cub3d->mlx.assets.north_wall.img_ptr, 0, 0);
	mlx_put_image_to_window(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr, cub3d->mlx.assets.south_wall.img_ptr, TEXTURE_SIZE, 0);
	mlx_put_image_to_window(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr, cub3d->mlx.assets.west_wall.img_ptr, 0, TEXTURE_SIZE);
	mlx_put_image_to_window(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr, cub3d->mlx.assets.east_wall.img_ptr, TEXTURE_SIZE, TEXTURE_SIZE);
	return (0);
}
