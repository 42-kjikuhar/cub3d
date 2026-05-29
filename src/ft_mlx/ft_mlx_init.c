/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 23:10:23 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/29 17:31:34 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./ft_mlx_private.h"

static bool	create_assets(t_settings *settings);

bool	ft_mlx_init(t_settings *settings)
{
	if (!create_mlx_connection() \
	|| !create_image(WINDOW_IMG, W_WIDTH, W_HEIGHT) \
	|| !create_assets(settings) \
	|| !create_window(W_WIDTH, W_HEIGHT, W_TITLE))
	{
		ft_mlx_destroy();
		return (false);
	}
	mlx_clear_window(mlx_ptr(), win_ptr());
	return (true);
}

static bool	create_assets(t_settings *settings)
{
	if (!create_image_from_xpm(settings->north_texture, \
				NORTH_WALL_IMG, TEXTURE_SIZE, TEXTURE_SIZE) \
		|| !create_image_from_xpm(settings->south_texture, \
				SOUTH_WALL_IMG, TEXTURE_SIZE, TEXTURE_SIZE) \
		|| !create_image_from_xpm(settings->west_texture, \
				WEST_WALL_IMG, TEXTURE_SIZE, TEXTURE_SIZE) \
		|| !create_image_from_xpm(settings->east_texture, \
				EAST_WALL_IMG, TEXTURE_SIZE, TEXTURE_SIZE))
	{
		return (false);
	}
	return (true);
}
